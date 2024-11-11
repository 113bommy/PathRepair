import gdb
import json

class StepAndTrace(gdb.Command):
    def __init__(self):
        super(StepAndTrace, self).__init__("trace", gdb.COMMAND_USER)
        gdb.events.stop.connect(self.stop_handler)
        self.stepping = False
        self.user_defined_symbols = set()
        self.cpp_filename = None
        self.execution_data = []
        self.json_name = None

    def set_json_name(self, json_name):
        self.json_name = json_name
        print(self.json_name)

    def load_cpp_filename(self, cpp_name):
        self.cpp_filename = cpp_name
        print(f'Loaded cpp file name = {self.cpp_filename}\n')
        
    def load_user_defined_symbols(self, filepath):
        """Load the symbols that are defined by the user and need to be tracked."""
        try:
            with open(filepath, 'r') as file:
                for line in file:
                    symbol = line.strip()
                    if symbol:
                        self.user_defined_symbols.add(symbol)
            print(f"Loaded user-defined symbols from {filepath}")
        except Exception as e:
            print(f"Error loading symbols from {filepath}: {e}")

    def stop_handler(self, event):
        """Handler to be called when the program stops."""
        if self.stepping and isinstance(event, gdb.StopEvent):
            try:
                if self.is_user_frame():
                    self.trace_all_variables()
            except gdb.error as e:
                print(f"Error during step handling: {e}")

    def is_user_defined(self, symbol):
        """Check if a symbol is user-defined and should be traced."""
        return symbol.name in self.user_defined_symbols

    def is_user_frame(self):
        """Check if the current frame is within the user's source code."""
        frame = gdb.newest_frame()
        sal = frame.find_sal()
        if sal.symtab:
            filename = sal.symtab.filename
            # return True
            return self.cpp_filename in filename
        return False

    def trace_all_variables(self):
        """Trace all variables currently available and initialized in the user frame."""
        frame = gdb.newest_frame()
        sal = frame.find_sal()
        if sal.symtab and sal.line:
            print(f"Stopped at {sal.symtab.filename}:{sal.line}")
            # Collect line data
            line_data = {
                'file': sal.symtab.filename,
                'line': sal.line,
                'variables': {}
            }

        while frame:
            try:
                block = frame.block()
            except RuntimeError as e:
                print(f"Error locating block for frame: {e}")
                break

            while block:
                for symbol in block:
                    if self.is_user_defined(symbol):
                        try:
                            value = symbol.value(frame)
                            # Check if the variable is initialized and accessible
                            if value.is_optimized_out:
                                print(f"{symbol.name} is optimized out.")
                                continue
                            if value.address:
                                print('===============Variable===============\n')
                                print(f"{symbol.name} = {value}")
                                print('\n==================END=================')
                                # Store variable data
                                line_data['variables'][symbol.name] = str(value)
                                print('data stored')
                        except gdb.error as e:
                            print(f"Error accessing value for {symbol.name}: {e}")
                block = block.superblock
            frame = frame.older()
        
        if line_data['variables']:
            self.execution_data.append(line_data)

    def save_execution_data(self):
        """Save the collected execution data to a JSON file."""
        with open(f'{self.json_name}.json', "w") as outfile:
            json.dump(self.execution_data, outfile, indent=4)

    def invoke(self, arg, from_tty):
        """Invoke the trace command with the given arguments."""
        args = gdb.string_to_argv(arg)
        if len(args) != 4:
            print("Usage: trace <symbol_file> <cpp_filename> <save_filename> <input_filename>")
            return
        
        filepath = args[0]
        cpp_name = args[1]
        json_name = args[2]
        input_filename = args[3]

        self.load_user_defined_symbols(filepath)
        self.load_cpp_filename(cpp_name)
        self.set_json_name(json_name)

        self.stepping = True

        try:
            gdb.execute(f'break main')
            gdb.execute(f"run < {input_filename}")
            while True:
                gdb.execute("step")
        except gdb.error as e:
            print(f"Error starting program: {e}")
            return
        finally:
            self.save_execution_data()


StepAndTrace()
