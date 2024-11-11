from collections import defaultdict, Counter
from math import sqrt, log10, log2, log, gcd, floor, factorial
from bisect import bisect_left, bisect_right
from itertools import combinations, combinations_with_replacement
import sys, io, os
input=sys.stdin.readline
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# print=sys.stdout.write
# sys.setrecursionlimit(10000)
mod = 10 ** 9 + 7;inf = float('inf')
def get_list(): return [int(i) for i in input().split()]
yn = lambda a: print("YES" if a else "NO")
ceil = lambda a, b: (a + b - 1) // b
t=1
for i in range(t):
    a,b=get_list()
    print(a+b)



