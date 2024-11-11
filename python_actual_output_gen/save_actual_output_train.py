import copy
import json
import subprocess
from math import isclose
import os
import chardet
import pandas as pd
import numpy as np
from tqdm import tqdm
from multiprocessing import Pool
from typing import Union
import multiprocessing
from transformers import RobertaTokenizer
import re

def read_jsonl_to_list(jsonl_file):
    data_list = []
    
    # Open and read the JSONL file
    with open(jsonl_file, 'r') as file:
        for line in file:
            # Parse each line as a JSON object and add it to the list
            data_list.append(json.loads(line))
    
    return data_list

def decode_output(output):
    result = chardet.detect(output)
    encoding = result['encoding']
    if not encoding:
        return output
    try:
        return output.decode(encoding)
    except (UnicodeDecodeError, AttributeError):
        return output  

def run_test_cases(file_path, input_data):
    try:
        process = subprocess.run(
            ['python', file_path], input=input_data + '\n', text=True, errors="replace", capture_output=True, timeout=2
        )
        try:
            if isinstance(process.stdout, bytes):
                decoded_output = decode_output(process.stdout)
                actual_output = repr(decoded_output.strip())
            else:
                actual_output = repr(process.stdout.strip())
        except Exception as decode_error:
            actual_output = "<decoding error>"
            print(f"Decoding error for process output: {decode_error}")
    except subprocess.TimeoutExpired as e:
        if e.stdout:
            try:
                if isinstance(e.stdout, bytes):
                    decoded_output = decode_output(e.stdout)
                    actual_output = repr(decoded_output.strip())
                else:
                    actual_output = repr(e.stdout.strip())
            except Exception as decode_error:
                actual_output = "<decoding error>"
                print(f"Decoding error for timeout process output: {decode_error}")
        else:
            actual_output = ""

        try:
            actual_output = actual_output.replace('\\n', '\n')
        except AttributeError:
            pass
        try:
            actual_output = actual_output.replace('\\t', '\t')
        except AttributeError:
            pass

    return actual_output

def make_python_file(file_path, code):
    with open(file_path, 'w') as f:
        f.write(code)

def save_dict_list_to_jsonl(data_list, filename):
    with open(filename, 'w') as file:
        for entry in data_list:
            json_line = json.dumps(entry)
            file.write(json_line + '\n')

def check_actual_output(args):
    single_data, input_data, input_output_data, variable_trace_data, statement = args
    script_file_path = f"./python_train_code/python_train_{single_data['pid']}_{single_data['code_index']}.py"
    make_python_file(script_file_path, single_data['raw_incorrect'])

    try:
        execute_result = subprocess.run(
            ["python", script_file_path],
            capture_output=True, text=True, timeout=0.5
        )
    except subprocess.TimeoutExpired:
        pass
    except Exception:
        with open(f'./python_error/error_train.txt', "w", encoding='utf-8') as err_log_file:
            err_log_file.write(f"{script_file_path}\n")

    actual_output = run_test_cases(script_file_path, input_data)[1:-1]
    if actual_output == '':
        return None
    # Removing '\\n' from actual output data
    actual_output = str(actual_output)
    actual_output = actual_output.replace('\\n', ' ').strip()
    # Removing '\n' from expected output data
    input_only_data = input_output_data.split('@Expected = [')[0]
    expected_data = input_output_data.split('@Expected = [')[-1].split(']')[0]
    expected_data = expected_data.replace('\n', ' ').strip()
    input_output_updated = input_only_data + '@Expected = [' + expected_data + ']'
    output_added_code = input_output_updated + f' @Actual = [{actual_output}] '
    single_data['input_expected_actual'] = output_added_code.strip()

    statement_split = statement.split('|||')
    lineno_split = []
    
    for single_statement in statement_split:
        match = re.search(r'^\d+', single_statement.strip())
        if match:
            lineno_split.append(match.group())

    gold_lineno = ', '.join(lineno_split)
    single_data['input_expected_actual_gold'] = output_added_code + f'@Location = [{gold_lineno}]'

    trace_added_code = output_added_code + '@Trace = ' + variable_trace_data 
    single_data['input_expected_actual_trace'] = trace_added_code.strip()

    tokenizer = RobertaTokenizer.from_pretrained("Salesforce/codet5-base")
    input_hf = tokenizer(trace_added_code, truncation=False)
    if len(input_hf.input_ids) > 400:
        return None
    return copy.deepcopy(single_data)

if __name__ == "__main__":
    data_path = './data/python_train_final_adjustment.jsonl'
    input_data = read_jsonl_to_list(data_path)

    tasks = []
    
    for single_data in input_data:
        trace_data = single_data['trace_code']
        input_data = trace_data.split('||| # @Input = [')[-1].split('] @Expected = [')[0]
        input_output_data = trace_data.split('] @Trace = ')[0]
        variable_trace_data = trace_data.split('] @Trace = ')[-1]
        tasks.append((single_data, input_data, input_output_data, variable_trace_data, single_data['statement']))
    
    final_result = []

    with multiprocessing.Pool(120) as pool:
        for result in tqdm(pool.imap_unordered(check_actual_output, tasks), total=len(tasks), ncols=60):
            if result is not None:
                final_result.append(result)

    save_dict_list_to_jsonl(final_result, './data/python_output_added_train.jsonl')
    print(f'Original Data : {len(tasks)}')
    print(f'Filtered Data : {len(final_result)}')