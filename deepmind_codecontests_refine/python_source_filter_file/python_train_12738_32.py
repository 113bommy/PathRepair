from itertools import product
from math import ceil

def binary_table(string_with_all_characters, length_to_make):
    return [''.join(x) for x in product(string_with_all_characters, repeat=length_to_make)]


def all_possible_substrings(string):
    return [string[i: j] for i in range(len(string)) for j in range(i + 1, len(string) + 1)]


def number_of_substrings(length):
    return int(length * (length + 1) / 2)


def is_prime(num):
    for i in range(2, num):
        if num / i == int(num / i) and num != i:
            return False

    return True


"""for enumeration in range(int(input())):
"""
inp = int(input())
builder = [0] * inp
if inp == 1:
    print(-1)
else:
    for i in range(1, inp + 1):
        builder[-i] = i
    print(*builder)