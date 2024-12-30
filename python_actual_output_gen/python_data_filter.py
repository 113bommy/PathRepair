import os
import copy
import json
import random
from tqdm import tqdm
from transformers import RobertaTokenizer

def read_jsonl_to_list(jsonl_file):
    data_list = []
    with open(jsonl_file, 'r') as file:
        for line in file:
            data_list.append(json.loads(line))
    return data_list
    
def save_dict_list_to_jsonl(data_list, filename):
    with open(filename, 'w') as file:
        for entry in data_list:
            json_line = json.dumps(entry)
            file.write(json_line + '\n')

def parse_trace_string(trace_string):
    """
    parse trace data
    Input = trace string (Formatted as "[1: {a: 20, b: 40} | 2: {a: 20, b: 40, c: 60} | 4: ]")
    Output = True / False (False if the trace data length is 0, otherwise True)
    """
    trace_content = trace_string.split('[', 1)[1].rsplit(']', 1)[0]
    result_dict = {}
    # Return False if trace string is empty
    if trace_string == '[]':
        return False

    for item in trace_content.split(' | '):
        key, value = item.split(':', 1)
        key = key.strip()
        # check each trace data has valid data
        if '{' in value and '}' in value:
            value_content = value.strip().strip('{}')
            sub_dict = {}
            for pair in value_content.split(' , '):
                pair = pair.strip()
                if len(pair) == 0:
                    continue
                k, v = pair.split(':', 1)
                sub_dict[k.strip()] = v.strip()
            result_dict[key] = sub_dict
            # Valid trace data - Return True
            return True
        else:
            result_dict[key] = None 
            
    # There is no valid trace data
    return False


def main():
    base_path = os.getcwd()
    single_case_data_path = os.path.join(base_path, './data/python_final_single_cases.jsonl')
    all_cases_data_path = os.path.join(base_path, './data/python_final_all_cases.jsonl')
    
    # Loading Trace added python data path
    path_dict = {
        'single' : single_case_data_path,
        'all' : all_cases_data_path
    }
    
    for d_t, single_path in tqdm(path_dict.items(), desc = 'single / all'):
        # Loading Trace added python data
        json_data = read_jsonl_to_list(single_path)

        save_list = []
        final_data_list = []
        
        for single_data in tqdm(json_data, desc = f'{d_t}', leave = True):
            if type(single_data['statement']) != str:
                continue
            
            # Parse expected / actual / trace data
            target_data = single_data['input_expected_actual_trace']
            expected_data = target_data.split('@Expected = [')[-1].split('] @Actual = [')[0].strip()
            actual_data = target_data.split('] @Actual = [')[-1].split(']')[0].strip()
            trace_data = target_data.split('] @Trace = ')[-1].strip()
            
            # Check whether each trace data has useful information
            if parse_trace_string(trace_data):
                # Check actual result and expected result is different
                if expected_data == actual_data:
                    continue
                else:
                    # Choose data only if actual result and expected result are different
                    if d_t == 'single':  
                        save_key = f"{single_data['pid']}_{single_data['code_index']}"
                        if save_key in save_list:
                            continue
                        else:
                            final_data_list.append(single_data)
                            save_list.append(save_key)
                    else:
                        final_data_list.append(single_data)
            else:
                # Exclude if trace data is not useful
                continue
            
        tqdm.write(f'{d_t} data length = {len(json_data)}')
        tqdm.write(f'filtered {d_t} data length = {len(final_data_list)}')
        save_dict_list_to_jsonl(final_data_list, os.path.join(base_path, f'python_final_filtered_{d_t}.jsonl'))

if __name__ == '__main__':
    main()