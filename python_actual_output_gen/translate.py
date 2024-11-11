import os
import json

def convert_json_to_jsonl(input_file, output_file):
    # Read the JSON data from the input file
    with open(input_file, 'r') as json_file:
        data = json.load(json_file)
    
    # Write the data to the JSONL file
    with open(output_file, 'w') as jsonl_file:
        for entry in data:
            jsonl_file.write(json.dumps(entry) + '\n')

cur_path = os.getcwd()
storage_path = os.path.join(cur_path, 'data')
data_path = [os.path.join(storage_path, single_data) for single_data in os.listdir(storage_path)] 

for single_data_path in data_path:
    convert_json_to_jsonl(single_data_path, f'{single_data_path}l')
