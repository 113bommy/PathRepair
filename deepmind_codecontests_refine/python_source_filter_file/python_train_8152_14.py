'''
    Rohit Kumar Vishwas
    13th June 2021
'''

import sys
import math
import os.path
from collections import *
from queue import *
from bisect import *
from heapq import *
# sys.setrecursionlimit(10 ** 6)
MOD = int(1e9 + 7)
inf = float('inf')
ninf = float('-inf')

input = sys.stdin.buffer.readline
def ii(): return list(map(int, input().strip().split()))
def deb(a, b="Debugging"): print(b, *a) if os.path.exists('inp.txt') else ""


for _ in range(int(input())):
    p = input()
    a1, a2 = ii()
    b1, b2 = ii()
    f1, f2 = ii()
    if a1 == b1 and a1 == f1 and (a2 <= f2 <= b2 or b2 <= f2):
        print(abs(a2-b2) + 2)
    elif a2 == b2 and a2 == f2 and (a1 <= f1 <= b1 or b1 <= f1 <= a1):
        print(abs(a1-b1) + 2)
    else:
        print(abs(a1-b1) + abs(a2 - b2))
