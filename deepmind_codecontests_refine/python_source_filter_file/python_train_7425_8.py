n = int(input())
dirs = ['/']

def ins_split(command):
    command = command.split('/')
    command[:] = [i for i in command if i != ""]
    command[:] = [i+'/' for i in command]
    return command
    

def display():
    # indexes to remove
    count = dirs.count('../')
    for _ in range(count):
        j = dirs.index('../')
        dirs.remove(dirs[j])
        dirs.remove(dirs[j-1])

    print(''.join(dirs))

while n:
    command = input() 
    if command == 'pwd': display()
    else:
        # removing cd part
        command = command[3:]

        # handling absolute path
        if command[0] == '/':
            command = ins_split(command)
            dirs[:] = command
        
        # handling relative
        else:
            command = ins_split(command)
            dirs += command
    n -= 1
