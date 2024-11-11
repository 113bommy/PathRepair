from collections import defaultdict
import collections
from heapq import heappush, heappop, heapify
from collections import deque, defaultdict, Counter
import itertools
from itertools import permutations, combinations, accumulate
import sys
import bisect
import string
import math
import time


def I(): return int(input())


def MI(): return map(int, input().split())


def S(): return input()


def MS(): return map(str, input().split())


def LI(): return [int(i) for i in input().split()]


def LI_(): return [int(i)-1 for i in input().split()]


def StoI(): return [ord(i)-97 for i in input()]


def ItoS(nn): return chr(nn+97)


def input(): return sys.stdin.readline().rstrip()


def print_matrix(mat):
    for i in range(len(mat)):
        print(*mat[i])


def show(*inp, end='\n'):
    if show_flg:
        print(*inp, end=end)


YN = {False: 'No', True: 'Yes'}
MOD = 10**9+7
inf = float('inf')
IINF = 10**10
l_alp = string.ascii_lowercase
u_alp = string.ascii_uppercase
nums = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10']

show_flg = False
# show_flg = True


def solve(T):
    n, k = MI()
    a = LI()
    MAX = 10**16 + 1
    v = 1

    while v < MAX:
        v *= k

    # print(v)

    while v > 0:
        for i in range(n):
            if a[i] >= v:
                a[i] -= v
                break
        v /= k

    # print(*a)
    if all([a[i] == 0 for i in range(n)]):
        print('YES')
    else:
        print('NO')


def main():
    T = I()

    for i in range(T):
        solve(T)


if __name__ == '__main__':
    main()
