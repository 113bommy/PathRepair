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

br =  False
num_of_digits, divisor = map(int, input().split())

num = int(f'1{"0" * (num_of_digits - 2)}')
if len(str(num)) > num_of_digits:
    print(-1)
else:
    while num % divisor:
        num += 1
        if len(str(num)) > num_of_digits:
            print(-1)
            br = True
            break
    if not br:
        print(num)