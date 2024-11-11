import sys
inputt=sys.stdin.readline
printt=sys.stdout.write

import math
import functools  # functools.reduce
from collections import deque
import heapq
from queue import PriorityQueue

def get():
    return inputt().split()
def getint():
    return int(inputt())
def getints():
    return map(int, inputt().split())

def f(start, a):
    c = [x for x in a]
    search = [0,0]
    n = 0
    for i in range(len(c)):
        x = c[i]
        if x != start:
            search[start] = max(i, search[start])
            for j in range(search[start], len(c)):
                if c[j] == start:
                    search[start] = j
                    break
            n += j-i
            c[i], c[j] = c[j], c[i]
        start = 1-start
    return n

for _ in range(getint()):
    n = getint()
    a = list(getints())
    odd = 0
    b = []
    for x in a:
        if x%2:
            odd+=1
        b.append(x%2)
    if n%2==0 and odd == n//2:
        print(min(f(0, b), f(1, b)))
    elif n%2!=0 and odd == n//2:
        print(f(0, b))
    elif n%2!=0 and odd == n//2 +1:
        print(f(1, b))
    else:
        print(-1)
