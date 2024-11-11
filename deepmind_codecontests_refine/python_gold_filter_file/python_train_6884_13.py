from collections import defaultdict, deque
from heapq import heappush, heappop
from math import inf

ri = lambda : map(int, input().split())

def solve():
    s = input()
    n = len(s)
    i = 0
    while i < n:
        if s[i] == "[":
            break
        i += 1
    if i == n:
        print(-1)
        return 
    j = n-1
    while j >= 0:
        if s[j] == "]":
            break
        j -= 1
    if i >= j:
        print(-1)
        return
    ans = 2 
    while i < j:
        if s[i] == ":":
            ans += 1
            break
        i += 1
    if i >= j:
        print(-1)
        return
    while j > i:
        if s[j] == ":":
            ans += 1
            break
        j -= 1
    if i >= j:
        print(-1)
        return
    for k in range(i, j):
        if s[k] == "|":
            ans += 1
    print(ans)
        


t = 1
#t = int(input())
while t:
    t -= 1
    solve()

