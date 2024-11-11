# from debug import *
import sys; input = sys.stdin.readline
from collections import deque, defaultdict
from math import log10, ceil, factorial as F

I =  lambda : int(input())
L = lambda : list(map(int, input().split()))
T = lambda : map(int, input().split())

n = I()
lis = L()
i = n-1
while i>0 and lis[i-1] < lis[i]: i-=1
print(n - i)
