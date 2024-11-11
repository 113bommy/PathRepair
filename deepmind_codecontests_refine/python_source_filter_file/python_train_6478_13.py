import os
import io
from collections import Counter
from collections import defaultdict
import math
import random
import heapq as hq
from math import sqrt
import sys
from functools import reduce
from collections import deque
import threading

# sys.setrecursionlimit(2000000)
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def input():
    return sys.stdin.readline().strip()


def iinput():
    return int(input())


def tinput():
    return input().split()


def rinput():
    return map(int, tinput())


def rlinput():
    return list(rinput())


mod = int(1e9)+7


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))


# ----------------------------------------------------
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')


if __name__ == "__main__":
    n = iinput()
    a = rlinput()
    b = rlinput()
    oz = 0
    zo = 0
    for i in range(n):
        if a[i] == 0 and b[i] == 1:
            zo += 1
        if a[i] == 1 and b[i] == 0:
            oz += 1
    if oz > zo:
        print(n)
    elif oz == 0:
        print(-1)
    else:
        print(zo//oz+1)
