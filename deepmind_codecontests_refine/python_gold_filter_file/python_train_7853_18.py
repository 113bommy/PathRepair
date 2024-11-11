from collections import defaultdict, deque
from heapq import heappush, heappop
from math import inf

ri = lambda : map(int, input().split())

def solve():
    n = int(input())
    cnt = defaultdict(int)
    A = list(ri())
    for x in A:
        cnt[x] += 1
    A.sort()
    if A[-1] == A[0]:
        print(0, max(1,(cnt[A[0]] * (cnt[A[0]]-1)) // 2))
        return
    print(A[-1] - A[0], cnt[A[0]] * cnt[A[-1]])

t = 1
#t = int(input())
while t:
    t -= 1
    solve()

