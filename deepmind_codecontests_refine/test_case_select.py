import json
import random
import os
from sklearn.utils import resample

def read_json(path):
    with open(path, 'r') as f:
        json_data = json.load(f)
    return json_data

def save_json(path, file):
    with open(path, 'w') as f:
        json.dump(file, f, indent = 4)

def test_case_sampling(input_data, output_data):
    random.seed(42)
    if len(input_data) < 10:
        oversampled_input = resample(input_data, replace=True, n_samples=10, random_state=42)
        oversampled_output = resample(output_data, replace=True, n_samples=10, random_state=42)
        return oversampled_input, oversampled_output
    else:
        sampled_indices = random.sample(range(len(input_data)), 10)
        sampled_input = [input_data[i] for i in sampled_indices]
        sampled_output = [output_data[i] for i in sampled_indices]
        return sampled_input, sampled_output

def count_test_case(python_dict):
    count = 0
    for key, value in python_dict.items():
        count += len(value['test_case']['input'])
    return count

if __name__ == "__main__":
    current_path = os.getcwd()
    data_type = ['test', 'valid', 'train'] 
    python_path = [os.path.join(current_path, 'python_data', f'python_{dt}_final_filtered.json') for dt in data_type]
    save_py_path = [os.path.join(current_path, 'python_data', f'python_{dt}_case_10.json') for dt in data_type]
    cpp_path = [os.path.join(current_path, 'cpp_data', f'cpp_{dt}_final_filtered.json') for dt in data_type]
    save_cpp_path = [os.path.join(current_path, 'cpp_data', f'cpp_{dt}_case_10.json') for dt in data_type]

    for (dt, save_path, py_path) in zip(data_type, save_py_path, python_path):
        py_dict = read_json(py_path)
        print(f'# Test case of Original {dt} Data {count_test_case(py_dict)}')
        for key, value in py_dict.items():
            input_data = value['test_case']['input']
            output_data = value['test_case']['output']
            assert len(input_data) == len(output_data)
            sampled_input, sampled_output = test_case_sampling(input_data, output_data)
            assert len(sampled_input) == 10
            assert len(sampled_output) == 10
            py_dict[key]['test_case']['input'] = sampled_input
            py_dict[key]['test_case']['output'] = sampled_output
        print(f'# Test case of Filtered {dt} Data {count_test_case(py_dict)}')
        save_json(save_path, py_dict)

    for (dt, save_path, cpp_path) in zip(data_type, save_cpp_path, cpp_path):
        cpp_dict = read_json(cpp_path)
        print(f'# Test case of Original {dt} Data {count_test_case(cpp_dict)}')
        for key, value in cpp_dict.items():
            input_data = value['test_case']['input']
            output_data = value['test_case']['output']
            assert len(input_data) == len(output_data)
            sampled_input, sampled_output = test_case_sampling(input_data, output_data)
            assert len(sampled_input) == 10
            assert len(sampled_output) == 10
            cpp_dict[key]['test_case']['input'] = sampled_input
            cpp_dict[key]['test_case']['output'] = sampled_output
        print(f'# Test case of Filtered {dt} Data {count_test_case(cpp_dict)}')
        save_json(save_path, cpp_dict)