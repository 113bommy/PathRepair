# YouTube
from collections import defaultdict
import sys

sys.setrecursionlimit(10 ** 6)

def dfs(u):
    ok[u] = 1
    for v in to[u]:
        if ok[v]: continue
        dfs(v)

def rdfs(u):
    ok[u] += 2
    for v in fr[u]:
        if ok[v] > 1: continue
        rdfs(v)

inf = 10 ** 9
to = defaultdict(list)
fr = defaultdict(list)
abc = []
n, m, p = map(int, input().split())
ok = [0] * n
for _ in range(m):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    c = -(c - p)
    to[a].append(b)
    fr[b].append(a)
    abc.append([a, b, c])
dfs(0)
rdfs(n - 1)
score = [inf] * n
score[0] = 0
for i in range(n):
    stop = True
    for a, b, c in abc:
        if ok[a] < 3 or ok[b] < 3: continue
        tmp = score[a] + c
        if tmp < score[b]:
            score[b] = tmp
            stop = False
    if stop:
        print(max(0, -score[n - 1]))
        break
else:
    print(-1)
