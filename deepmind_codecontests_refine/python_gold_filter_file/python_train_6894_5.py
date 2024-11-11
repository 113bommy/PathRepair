from sys import stdin
from collections import deque
mod = 10**9 + 7
import sys
import random
# sys.setrecursionlimit(10**6)
from queue import PriorityQueue
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
from itertools import permutations
from math import factorial as f

def ncr(x, y):
    return f(x) // (f(y) * f(x - y))

from collections import defaultdict
from heapq import heappop, heappush, heapify

t = int(input())

for _ in range(t):
    a,b = map(int,input().split())

    if a%b == 0 or b%a == 0:
        print('YES')
    else:
        print('NO')


