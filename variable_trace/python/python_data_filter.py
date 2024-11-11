import os
import copy
import json
import random
from tqdm import tqdm
from transformers import RobertaTokenizer

def read_json(path):
    with open(path, 'r') as f:
        json_data = json.load(f)
    return json_data

def save_json(file, path):
    with open(path, 'w') as f:
        json.dump(file, f, indent = 4)

def main():
    base_path = os.getcwd()
    python_data_path = os.path.join(base_path, 'python_data')
    data_type = ['test', 'valid', 'train']

    for s_t in tqdm(data_type, desc = 'test, valid, train'):
        data_path = os.path.join(python_data_path, f'python_{s_t}_trace_added.json')
        json_data = read_json(data_path)
        tqdm.write(f'len(data) {len(json_data)}')

        save_list = []
        final_data_list = []
        
        for single_data in tqdm(json_data, desc = 'Progress', leave = True):
            if type(single_data['statement']) != str:
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
        save_json(final_data_list, os.path.join(python_data_path, f'python_{s_t}_final_choose_1.json'))

if __name__ == '__main__':
    main()