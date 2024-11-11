import os
import json
from tqdm import tqdm

def make_cpp_file(pid, code_index, code):
    with open(f'./cpp_code/cpp_correct/cpp_correct_test_{pid}_{code_index}.cpp', 'w') as f:
        f.write(code[0])
    with open(f'./cpp_code/cpp_incorrect/cpp_incorrect_test_{pid}_{code_index}.cpp', 'w') as f:
        f.write(code[1])

def make_input_file(pid, input_index, input):
    with open(f'./cpp_input/cpp_test_{pid}_{input_index}.txt', 'w') as f:
        f.write(input)

def read_json(path):
    with open(path, 'r') as f:
        json_data = json.load(f)
    return json_data

if __name__ == "__main__":

    input_json = './cpp_data/cpp_test_case_10.json'
    input_data = read_json(input_json)

    for key, value in tqdm(input_data.items(),leave = True):
        for code_index, code_value in enumerate(value['code_pair']):
            make_cpp_file(key, code_index, code_value)
            for tc_index, (tc_input, _) in enumerate(zip(value['test_case']['input'], value['test_case']['output'])):
                make_input_file(key, tc_index, tc_input)
