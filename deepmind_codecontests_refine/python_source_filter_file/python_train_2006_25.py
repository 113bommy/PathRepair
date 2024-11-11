from sys import stdin, stdout
import heapq
import cProfile
from collections import Counter, defaultdict, deque
from functools import reduce
import math


def get_int():
    return int(stdin.readline().strip())


def get_tuple():
    return map(int, stdin.readline().split())


def get_list():
    return list(map(int, stdin.readline().split()))


def solve():
    n,k = get_tuple()
    if n>k:
        print(n%2)
    elif n==k: print(0)
    else:
        print(k-n)







def main():
    solve()


TestCases = True

if TestCases:
    for i in range(get_int()):
        main()
else:
    main()
