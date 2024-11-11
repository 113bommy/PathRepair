import sys
from math import log2, floor

TEST = 0

if TEST == 1:
    input_file = open("inputA.txt", "r")
    input_from_file = input_file.readlines()

def read_int():
    if TEST:
        return int(input_from_file.pop(0))
    else:
        return int(sys.stdin.readline())

def read_ints():
    if TEST:
        return list(map(int, input_from_file.pop(0).rstrip().split()))
    else:
        return list(map(int, sys.stdin.readline().split()))

def read_str_to_list():
    if TEST:
        in1 = input_from_file.pop(0).rstrip()
    else:
        in1 = sys.stdin.readline().rstrip()
    return [x for x in in1]

t = read_int()


for test in range(t):
    b = read_str_to_list()

    lenb = len(b)
    a = []
    for j in range(int(lenb/2)):
        a.append(b[2*j])

    a.append(b[-1])

    print(''.join(a))



