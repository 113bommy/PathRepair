from sys import stdin
from collections import deque
mod = 10**9 + 7
import sys
# sys.setrecursionlimit(10**5)
# def rl():
#     return [int(w) for w in stdin.readline().split()]
from bisect import bisect_right
from bisect import bisect_left
from collections import defaultdict
from math import sqrt,factorial,gcd,log2,inf,ceil
# map(int,input().split())
# # l = list(map(int,input().split()))
# from itertools import permutations
import heapq
# input = lambda: sys.stdin.readline().rstrip()
input = lambda : sys.stdin.readline().rstrip()
from sys import stdin, stdout
from heapq import heapify, heappush, heappop

import sys

X = int(sys.stdin.readline())

a = set([int(i) for i in sys.stdin.readline().split()])

top = 1<<31
ans = 0

def best(s, cur):
    if len(s) == 0 or cur==0:
        return 0
    hasCur = set()
    hasNotCur = set()
    for i in s:
        if i&cur == 0:
            hasNotCur.add(i)
        else:
            hasCur.add(i)

    if len(hasNotCur)==0 or len(hasCur)==0:
        # print(s,cur)
        return best(s, cur>>1)
    else:
        print(s,cur)
        return cur + min(best(hasNotCur, cur>>1), best(hasCur, cur>>1))


print(best(a, top))


