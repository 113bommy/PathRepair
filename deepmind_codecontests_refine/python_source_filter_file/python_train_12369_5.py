import sys
from collections import defaultdict
sys.setrecursionlimit(100000)

N, M = map(int, input().split())
AB = defaultdict(list)
gain = [0]*N
for i in range(N + M - 1):
    a, b = map(int, input().split())
    AB[a - 1].append(b - 1)
    gain[b - 1] += 1

ans = [None]*N
def rec(u, p):
    ans[u] = p
    for v in AB[u]:
        gain[v] -= 1
    for v in AB[u]:
        if gain[v] == 0 and ans[v] is None:
            rec(v, u)

root = gain.index(0)
rec(root, -1)

for i in range(N):
    print(ans[i] + 1)
