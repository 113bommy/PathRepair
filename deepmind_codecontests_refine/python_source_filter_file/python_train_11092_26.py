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


num_of_particles = int(input())
movement_directions = input()
array = list(map(int, input().split()))
num = 0
cond = False
all_ = set()
for i in range(len(movement_directions)):
    x = movement_directions[i: i + 2]
    print(x)
    if x == 'RL':
        xd = array[i: i + 2]
        all_.add(int(abs(xd[0] - xd[1]) / 2))

if all_:
    print(min(all_))
else:
    print(-1)