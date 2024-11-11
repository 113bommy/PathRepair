import os
import copy
import json
import random
from tqdm import tqdm
from transformers import RobertaTokenizer

def read_jsonl_to_list(jsonl_file):
    data_list = []
    
    # Open and read the JSONL file
    with open(jsonl_file, 'r') as file:
        for line in file:
            # Parse each line as a JSON object and add it to the list
            data_list.append(json.loads(line))
    
    return data_list
    
def save_dict_list_to_jsonl(data_list, filename):
    with open(filename, 'w') as file:
        for entry in data_list:
            json_line = json.dumps(entry)
            file.write(json_line + '\n')

def main():
    base_path = os.getcwd()
    data_type = ['valid', 'train']

    for s_t in tqdm(data_type, desc = 'test, valid, train'):
        data_path = os.path.join(base_path, f'./data/python_output_added_{s_t}.jsonl')
        json_data = read_jsonl_to_list(data_path)
        tqdm.write(f'len(data) {len(json_data)}')

        save_list = []
        final_data_list = []
        
        for single_data in tqdm(json_data, desc = 'Progress', leave = True):
            if type(single_data['statement']) != str:
                continue
            
            target_data = single_data['input_expected_actual']
            expected_data = target_data.split('@Expected = [')[-1].split('] @Actual = [')[0].strip()
            actual_data = target_data.split('] @Actual = [')[-1].split(']')[0].strip()
            
            if expected_data == actual_data:
                continue
            else:
                save_key = f"{single_data['pid']}_{single_data['code_index']}"
                if save_key in save_list:
                    continue
                else:
                    final_data_list.append(single_data)
                    save_list.append(save_key)

        tqdm.write(f'final len {len(final_data_list)}')
        random.shuffle(final_data_list)
        save_dict_list_to_jsonl(final_data_list, os.path.join(base_path, f'final_data_{s_t}.jsonl'))

if __name__ == '__main__':
    main()