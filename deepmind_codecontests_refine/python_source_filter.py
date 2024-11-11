from tqdm import tqdm
import json
import os
import numpy as np

def make_numpy(result_json):
    result = result_json['results']
    code_index_list = []
    test_result_list = []
    for single_result in result:
        code_index_list.append(single_result[0])
        test_result_list.append(single_result[1])
    np_test_result = np.array(test_result_list)

    return (code_index_list, np_test_result)

# Selecting appropriate correct codes and test cases

def refine_data(code_index_list, np_test_result):
    any_zero_indices = np.where(np.any(np_test_result == 0, axis=1))[0]
    source_code_index = [code_index_list[source_index] for source_index in any_zero_indices]
    np_source_code = np_test_result[any_zero_indices]
    threshold = 0.7 * np_source_code.shape[0]
    test_case_index = np.where(np.sum(np_source_code == 1, axis=0) <= threshold)[0]

    return test_case_index, source_code_index

def check_result(result_path):
    final_test_case = {}
    
    for index, check_file in tqdm(enumerate(os.listdir(result_path)), leave = True):
        pid = check_file.split('_')[-1].split('.json')[0] 
        file_path = os.path.join(result_path, check_file)
        with open(file_path, 'r') as f:
            result_json = json.load(f)

        code_index_list, np_test_result = make_numpy(result_json)
        test_case_index, source_code_index = refine_data(code_index_list, np_test_result)

        final_test_case[pid] = [test_case_index.tolist(), source_code_index]

    return final_test_case

def extract_values(indices, raw_test_case, raw_code_pair):
    input_values = raw_test_case['input']
    output_values = raw_test_case['output']
    
    test_case_refine = {
        'input': [input_values[i] for i in indices[0]],
        'output': [output_values[i] for i in indices[0]]
    }
    code_refine = [raw_code_pair[j] for j in indices[1]]

    return test_case_refine, code_refine

def data_filter(final_test_case, data_dict):

    final_test_case_key = final_test_case.keys()

    for key, value in final_test_case.items():
        raw_test_case = data_dict[key]['test_case']
        raw_code_pair = data_dict[key]['code_pair']
        extract_test_case, extract_code = extract_values(value, raw_test_case, raw_code_pair)
        data_dict[key]['test_case'] = extract_test_case
        data_dict[key]['code_pair'] = extract_code

    for key, value in data_dict.items():    
        if key not in final_test_case_key:
            data_dict[key]['test_case'] = {
                'input': [],
                'output': []
            }
    
    del_dict = []

    for key, value in data_dict.items():
        if (len(value['test_case']['input']) == 0) & (len(value['test_case']['output']) == 0):
            del_dict.append(key)
            continue
        if len(value['code_pair']) == 0:
            del_dict.append(key)
            continue

    for del_key in del_dict:
        del data_dict[del_key]

    return data_dict 

def count_test_case(python_dict):
    count = 0
    for key, value in python_dict.items():
        count += len(value['test_case']['input'])
    return count

def count_code(python_dict):
    count = 0
    for key, value in python_dict.items():
        if len(value['test_case']['input']) != 0:
            count += len(value['code_pair'])

    return count

np.set_printoptions(threshold=np.inf)
curr_path = os.getcwd()

python_test_result_path = os.path.join(curr_path, 'python_test_source_result')
python_valid_result_path = os.path.join(curr_path, 'python_valid_source_result')
python_train_result_path = os.path.join(curr_path, 'python_train_source_result')

python_test_gold_filter_path = os.path.join(curr_path, 'python_data', 'python_test_gold_filtered.json')
python_valid_gold_filter_path = os.path.join(curr_path, 'python_data', 'python_valid_gold_filtered.json')
python_train_gold_filter_path = os.path.join(curr_path, 'python_data', 'python_train_gold_filtered.json')

with open(python_test_gold_filter_path, 'r') as f:
    python_test = json.load(f)
with open(python_valid_gold_filter_path, 'r') as f:
    python_valid = json.load(f)
with open(python_train_gold_filter_path, 'r') as f:
    python_train = json.load(f)

print(f'# Gold filtered Test case of test_check_result {count_test_case(python_test)}')
print(f'# Gold filtered Test case of valid_check_result {count_test_case(python_valid)}')
print(f'# Gold filtered Test case of train_check_result {count_test_case(python_train)}')

print(f'# Gold filtered Code pair of test_check_result {count_code(python_test)}')
print(f'# Gold filtered Code pair of valid_check_result {count_code(python_valid)}')
print(f'# Gold filtered Code pair of train_check_result {count_code(python_train)}')

test_check_result = check_result(python_test_result_path)
valid_check_result = check_result(python_valid_result_path)
train_check_result = check_result(python_train_result_path)

source_filter_test = data_filter(test_check_result, python_test)
source_filter_valid = data_filter(valid_check_result, python_valid)
source_filter_train = data_filter(train_check_result, python_train)

print(f'# source filtered test case of test_check_result {count_test_case(source_filter_test)}')
print(f'# source filtered test case of valid_check_result {count_test_case(source_filter_valid)}')
print(f'# source filtered test case of train_check_result {count_test_case(source_filter_train)}')

print(f'# source filtered Code pair of test_check_result {count_code(source_filter_test)}')
print(f'# source filtered Code pair of valid_check_result {count_code(source_filter_valid)}')
print(f'# source filtered Code pair of train_check_result {count_code(source_filter_train)}')

with open(f'./python_data/python_test_final_filtered.json', 'w') as f:
    json.dump(source_filter_test, f, indent=4)

with open(f'./python_data/python_valid_final_filtered.json', 'w') as f:
    json.dump(source_filter_valid, f, indent=4)

with open(f'./python_data/python_train_final_filtered.json', 'w') as f:
    json.dump(source_filter_train, f, indent=4)