from collections import defaultdict, deque
from heapq import heappush, heappop
from math import inf

ri = lambda : map(int, input().split())

def solve():
    n = int(input())
    A = list(ri())
    total = sum(A)
    curr = 0
    for i in range(n):
        curr += A[i]
        if curr >= total // 2:
            print(i+1)
            return

t = 1
#t = int(input())
while t:
    t -= 1
    solve()

