from itertools import product
from math import ceil
import string


def binary_table(string_with_all_characters, length_to_make):
    return [''.join(x) for x in product(string_with_all_characters, repeat=length_to_make)]


def all_possible_substrings(string):
    return [int(string[i: j]) for i in range(len(string)) for j in range(i + 1, len(string) + 1)]


def number_of_substrings(length):
    return int(length * (length + 1) / 2)


def is_prime(num):
    for i in range(2, num):
        if num / i == int(num / i) and num != i:
            return False

    return True


num_of_lines = int(input())
build_letter = ''
cond = False
cond_2 = False
position_1 = ''
position_2 = ''
arr = set()
aller = set()
for i in range(num_of_lines):
    inp = input()
    if i == 0:
        if inp[0] == inp[-1]:
            build_letter = inp[0]
            position_1 = 0
            position_2 = len(inp) - 1
            positions = [x for x in range(len(inp)) if inp[x] == build_letter]
            if len(positions) > 2:
                cond = True
                break
        else:
            cond = True
            break
    else:
        if position_1 == position_2:
            cond_2 = True

        if cond_2:
            position_1 -= 1
            position_2 += 1
        else:
            position_1 += 1
            position_2 -= 1
        positions = [x for x in range(len(inp)) if inp[x] == build_letter]
        #print(positions, build_letter, inp)
        #print(build_letter)
        #print(inp)
        if len(positions) > 2:
            cond = True
            break
        elif len(positions) == 1:
            if positions[0] != position_1 or positions[0] != position_2:
                cond = True
                break
        elif len(positions) == 0:
            cond = True
            break
        elif position_1 != positions[0] or position_2 != positions[1]:
            cond = True
            break
    arr.add(inp)
if not cond:
    for i in arr:
        for j in i:
            aller.add(j)
    if len(aller) == 2:
        print('YES')
    else:
        print('NO')
else:
    print('NO')
