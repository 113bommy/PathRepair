from itertools import product
from math import ceil, gcd, sqrt
import string
from decimal import Decimal


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


num = int(input())
path = input()

if path.count('R') == 0:
    val = path.index('L') + 1
    print(val, val + 1)
elif path.count('L') == 0:
    val = path.index('R') + 1
    counter = path.count('R')
    print(val, val + counter)
else:
    l_num = 0
    print(path.index('R') + 1, path.index('L'))