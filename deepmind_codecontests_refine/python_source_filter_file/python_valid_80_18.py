from collections import deque
import heapq
from math import sqrt
import operator
from operator import itemgetter
import sys

import copy

 
inf_var = 0
if inf_var == 1:
    inf = open('input.txt', 'r')
else:
    inf = sys.stdin
 
input = inf.readline
# sys.stdout = open('output.txt', 'w')
 
def read_one_int():
    return int(input().rstrip('\n'))


def read_one_float():
    return float(input().rstrip('\n'))
 
 
def read_list_of_ints():
    res = [int(val) for val in (input().rstrip('\n')).split(' ')]
    return res
 
def read_str():
    return input().rstrip()


def main():
    tests = read_one_int()

    for _ in range(tests):
        n = read_one_int()

        cur_str = read_str()
        res = []
        allowed_len = n // 2

        for i in range(n - 1, 0, -1):
            if i < allowed_len:
                break

            if cur_str[i - 1] == '1' and cur_str[i] == '0':
                res = [1, i, 1, i + 1]
                break

        if res:
            print(' '.join(map(str, res)))
            continue

        for i in range(n - 1):
            if n - i - 1 < allowed_len:
                break

            if cur_str[i] == '0':
                res = [i + 1, n, i + 2, n]
                break

        if res:
            print(' '.join(map(str, res)))
            continue

        res = [1, (n // 2) * 2, 1, n // 2]
        print(' '.join(map(str, res)))

            
if __name__== '__main__':
    main()
