import sys
import re


def has_numbers(string):
    return bool(re.search(r'\d', string))


def parse_by_map(only_strings=False):
    lines = []
    for line in sys.stdin:
        if not has_numbers(line) or only_strings:
            lines.append(map(str, line.strip().split(" ")))
        else:
            lines.append(map(int, line.strip().split(" ")))
    return lines


def map_collection_to_list_collection(map_collection):
    list_collection = []
    for collection in map_collection:
        list_collection.append(list(collection))
    return list_collection


def assign_client(list1):
    for idx, status in enumerate(list1):
        if status == 0:
            list1[idx] = 1
            break
    return list1


if __name__ == '__main__':

    input_map = parse_by_map(only_strings=True)
    input_list = map_collection_to_list_collection(input_map)
    rooms_status = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    sequence = input_list[1][0]
    for move in sequence:
        if move == "L":
            rooms_status = assign_client(rooms_status)
        elif move == "R":
            rooms_status.reverse()
            rooms_status = assign_client(rooms_status)
            rooms_status.reverse()
        else:
            rooms_status[int(move)] = 0
    for i in rooms_status:
        print(i, end="")
