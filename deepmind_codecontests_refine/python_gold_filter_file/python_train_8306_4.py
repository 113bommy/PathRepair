# AGC033C

import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


from collections import defaultdict
n = int(input())
ns = defaultdict(set)
for _ in range(n-1):
    u,v = map(int, input().split())
    ns[u-1].add(v-1)
    ns[v-1].add(u-1)

def bfs(start):
    from queue import deque
    q = deque([start])
    seen = [None] * n
    seen[start] = 0
    dd = 0
    target = start
    while q:
        u = q.pop()
        d = seen[u]
        if d>dd:
            dd = d
            target = u
        for v in ns[u]:
            if seen[v] is None:
                seen[v] = d + 1
                q.appendleft(v)
    return target, dd
target, tmp = bfs(0)
_, d = bfs(target)
if (d-1)%3!=0:
    print("First")
else:
    print("Second")