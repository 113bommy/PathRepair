import sys
from collections import deque

def solve():
    n = int(input())
    a = [val - 1 for val in list(map(int, input().split()))]
    queue = deque([(0, 0)])
    ans = [-1] * n
    while len(queue) > 0:
        cur = queue.pop()
        if cur[0] < 0 or cur[0] >= n or ans[cur[0]] != -1: continue
        ans[cur[0]] = cur[1]
        queue.append((cur[0] - 1, cur[1] + 1))
        queue.append((cur[0] + 1, cur[1] + 1))
        queue.append((a[cur[0]], cur[1] + 1))
    print(" ".join(map(str, ans)))

if sys.hexversion == 50659824: sys.stdin = open("input.txt")
solve()