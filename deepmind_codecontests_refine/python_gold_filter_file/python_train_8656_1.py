import itertools
import math
import sys
import heapq
from collections import Counter
from collections import deque
from fractions import gcd
from functools import reduce

sys.setrecursionlimit(4100000)
INF = 1 << 60
MOD = 10 ** 9 + 7

# ここから書き始める
t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    yes = False
    for j in range(n):
        if j + 10 >= n:
            break
        if s[j] == "8":
            # print("YES")
            yes = True
            break
    if yes:
        print("YES")
    else:
        print("NO")
