import os
import json
import gzip
import shutil
import random
import argparse
from multiprocessing import Pool, cpu_count
from transformers import RobertaTokenizer
from tqdm import tqdm


def read_json(path):
    with open(path, 'r') as f:
        return json.load(f)

def save_json(file, path):
    with open(path, 'w') as f:
        json.dump(file, f, indent=4)


def open_gz(data_path: str) -> dict:
    with gzip.open(data_path, 'rt', encoding='utf-8') as f:
        return json.load(f)

def compare_dict(dict1, dict2):
    key_set = set(dict1.keys()).union(set(dict2.keys()))

    differences = {}
    
    for key in key_set:
        if key not in dict1:
            differences[key] = f'{dict2[key]}'
        elif key not in dict2:
            differences[key] = f'returned'
        elif dict1[key] != dict2[key]:
            differences[key] = f'{dict1[key]} -> {dict2[key]}'
    
    return differences

def compress_file(input_file, output_file):
    with open(input_file, 'rb') as f_in:
        with gzip.open(output_file, 'wb') as f_out:
            shutil.copyfileobj(f_in, f_out)

            
def detect_complete_loops(parsed_code):
    lines = parsed_code.split('|||')
    in_loop = False
    loop_structure = []
    detected_loops = []  # List to store all detected loop structures

    for line in lines:
        # Strip leading/trailing spaces from the line
        line = line.strip()
    
        if line:  # Process non-empty lines
            # Try splitting line number and statement safely
            parts = line.split(' ', 1)
            
            # Ensure both line number and statement exist before unpacking
            if len(parts) == 2:
                line_number, statement = parts
                line_number = line_number.strip()
                statement = statement.rstrip()
                # Check if the current line is the start of a loop (for or while)
                if statement.startswith("for ") or statement.startswith("while "):
                    in_loop = True  # Start capturing the loop structure
                    loop_structure.append(int(line_number))
                elif in_loop:
                    # Loop block continues while indented
                    if statement.startswith("  ") or statement.startswith('\t'):  # Indentation is 4 spaces, representing a block
                        loop_structure.append(int(line_number))
                    else:
                        # Stop capturing if indentation is gone (end of loop body)
                        in_loop = False
                        if loop_structure:
                            # Add the detected loop to the list
                            detected_loops.append(loop_structure)
                            loop_structure = []  # Reset for the next loop
            else:
                pass
        else:
            # If the line is empty, continue processing
            if in_loop:  # Ignore empty lines within a loop body
                continue
    
    # If we reach the end of the code and were still in a loop, add the remaining structure
    if in_loop and loop_structure:
        detected_loops.append(loop_structure)

    return detected_loops  # Return the list of detected loops

def track_final_changes(differences_list):
    # Initialize a dictionary to store the final changes
    final_changes = {}

    # Iterate through each differences dictionary in the list
    for differences in differences_list:
        for key, change in differences.items():
            # Parse the changes (if it's a transition like "old -> new", keep the new value)
            if '->' in change:
                # Extract the final value from the change
                new_value = change.split('->')[-1].strip()
                final_changes[key] = new_value
            else:
                # If it's just a new addition or removal, store that
                final_changes[key] = change
    
    return final_changes

def group_consecutive_numbers(nums):
    if not nums:
        return []
    # sort the list
    nums = sorted(nums)
    
    # Generate first group
    grouped = [[nums[0]]]

    for i in range(1, len(nums)):
        # if the number is continuous
        if nums[i] == nums[i - 1] + 1:
            grouped[-1].append(nums[i])  # append at last one
        else:
            grouped.append([nums[i]])  # genearate new group

    return grouped

def find_data_in_nested_list(nested_list, target):
    # find data in list
    for inner_list in nested_list:
        if target in inner_list:
            return inner_list  
    return None 

def compress_trace(trace_data: dict, loop_detect: list) -> str:
    trace_data_list = []
    difference_data_list = []
    trace_string_list = []

    # Compress trace data due to token limit
    for step, trace in trace_data.items():
        line_number = int(trace['line'])
        variable = trace['variables']
        trace_data_list.append((line_number, variable))

    for index in range(len(trace_data_list) - 1):
        previous_lineno, previous_data = trace_data_list[index]
        new_lineno, new_data = trace_data_list[index + 1]
        differences = compare_dict(previous_data, new_data)
        difference_data_list.append((previous_lineno - 1, differences))

    loop_dict = {}

    for index, (lineno, diff_data) in enumerate(difference_data_list):
        for single_loop in loop_detect:
            if lineno in single_loop:
                if str(single_loop) not in loop_dict.keys():
                    loop_dict[str(single_loop)] = [index]
                else:
                    loop_dict[str(single_loop)].append(index)
                break

    grouped_dict = {}

    for loop_name, loop_list in loop_dict.items():
        grouped_dict[loop_name] = group_consecutive_numbers(loop_list)

    final_index = 0

    while(1):
        if final_index >= len(difference_data_list):
            break

        lineno, diff_data = difference_data_list[final_index]
        if lineno == 0:
            final_index += 1
            continue

        find_data = None  
        
        for loop_name, single_nested_list in grouped_dict.items():
            find_data = find_data_in_nested_list(single_nested_list, final_index)
            if find_data is not None:
                break

        if find_data is not None:
            single_loop_data = []
            for i in find_data:
                _, diff = difference_data_list[i]
                single_loop_data.append(diff)

            compressed_loop = track_final_changes(single_loop_data)
            trace_string_list.append(f'{loop_name}: ' + '{' + ' , '.join([f'{k}: {v}' for k, v in compressed_loop.items()]) + '}')
            final_index = find_data[-1] + 1
        else:
            if len(diff_data.keys()) == 0:
                trace_string_list.append(f'{lineno}: ')
            else:
                trace_string_list.append(f'{lineno}: ' + '{' + ' , '.join([f'{k}: {v}' for k, v in diff_data.items()]) + '}')

            final_index += 1

    return ' | '.join(trace_string_list)


def process_code(args):
    pid_index, incorrect_data, pid_split_dict, tokenizer = args
    trace_added_list = []

    split_index = os.path.basename(incorrect_data).split('_')
    code_index = split_index[3]
    case_index = split_index[4].split('.json')[0]

    # Load data from original incorrect data
    stored_data = pid_split_dict[pid_index][int(code_index)]
    stored_index, full_data = stored_data
    assert int(code_index) == int(stored_index)

    # Make trace comment added code
    input_data = full_data['test_case']['input'][int(case_index)]
    output_data = full_data['test_case']['output'][int(case_index)]

    loop_detect_data = full_data['incorrect_code']
    loop_detect = detect_complete_loops(loop_detect_data)

    # Generate trace compressed data
    single_incorrect_trace = open_gz(incorrect_data)
    compressed_trace = compress_trace(single_incorrect_trace, loop_detect)

    full_comment = ' # @Input = [' + input_data +  '] @Expected = [' + output_data + '] @Trace = [' + compressed_trace + ']'

    trace_added_code = full_data['incorrect_code'] + full_comment
    full_data['trace_code'] = trace_added_code
    full_data['code_index'] = int(code_index)

    # Choose only data whose token length is under 512(Maximum Token length of CodeT5 model)
    input_hf = tokenizer(trace_added_code, truncation=False)
    if len(input_hf.input_ids) > 512:
        return trace_added_list  # Skip if too long
    
    if 'def main' in full_data['incorrect_code']:
        return trace_added_list

    # Save the full data
    trace_added_list.append(full_data)
    return trace_added_list


def main():
    base_path = os.getcwd()
    trace_path = os.path.join(base_path, 'python_trace')
    tokenizer = RobertaTokenizer.from_pretrained("Salesforce/codet5-base")
    
    parser = argparse.ArgumentParser()
    parser.add_argument('--data_split', type = str, help = 'valid. test, train')
    parser.parse_args()
    args = parser.parse_args()
    data_type = args.data_split
    
    split_type = [data_type]

    for s_t in tqdm(split_type, desc='Valid, Test, Train'):
        pid_split_dict = {}
        all_trace_added_list = []

        trace_type_path = os.path.join(trace_path, s_t, 'python_incorrect')
        data_list = os.listdir(trace_type_path)
        json_file_path = os.path.join(base_path, 'python_data', f'python_{s_t}_baseline_400.json')
        raw_json = read_json(json_file_path)

        # Split the data based on problem id
        for single_storage in raw_json:
            pid_index = single_storage['pid']
            if pid_index in pid_split_dict:
                pid_split_dict[pid_index].append((len(pid_split_dict[pid_index]), single_storage))
            else:
                pid_split_dict[pid_index] = [(0, single_storage)]

        # Prepare arguments for multiprocessing
        args_list = []
        for pid_index in data_list:
            pid_path = os.path.join(trace_type_path, pid_index)
            incorrect_list = os.listdir(pid_path)

            for single_incorrect in incorrect_list:
                incorrect_data = os.path.join(pid_path, single_incorrect)
                args_list.append((pid_index, incorrect_data, pid_split_dict, tokenizer))

        # Use multiprocessing Pool
        with Pool(120) as pool:  # Use one less CPU than available
            for result in tqdm(pool.imap_unordered(process_code, args_list, chunksize=250), total=len(args_list), desc="Processing Codes"):
                all_trace_added_list.extend(result)

        # Save the results
        save_json(all_trace_added_list, os.path.join(base_path, 'python_data', f'python_{s_t}_final_adjustment.json'))


if __name__ == '__main__':
    main()
