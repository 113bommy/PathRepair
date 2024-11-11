from collections import Counter
from functools import reduce
from math import acos, ceil, cos, floor, pi, sin, sqrt, log10
from random import random
from string import ascii_lowercase, ascii_uppercase, digits
from sys import exit, setrecursionlimit, stdin
dX = [-1, 1, 0, 0, -1, 1, -1, 1]
dY = [0, 0, -1, 1, 1, -1, -1, 1]
mod = int(1e9 + 7)
eps = 1e-6
MAX = 3*10**5 + 10
#################################################
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    firstZero = s.find('0') + 1
    if firstZero == 0:
        print(1, n-1, 2, n)
    elif firstZero > n//2:
        print(1, firstZero, 1, firstZero-1)
    else:
        print(firstZero + 1, n, firstZero, n)