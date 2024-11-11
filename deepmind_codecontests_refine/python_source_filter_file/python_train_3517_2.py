import time, sys
sys.setrecursionlimit(int(1e7))

n, m, k = map(int, input().split())

friends = [[] for i in range(n)]
cands = [None for i in range(n)]
cycles = []
visited = [False for i in range(n)]
count = [0 for i in range(n)]
for _ in range(m):
    a, b = map(lambda x: int(x)-1, input().split())
    friends[a].append(b)
    friends[b].append(a)

def dfs(x):
    visited[x] = True
    cycle.append(x)
    for i in friends[x]:
        if not visited[i]:
            dfs(i)
    return


for i, v in enumerate(visited):
    if v:
        continue
    cycle = []
    dfs(i)
    l = len(cycle)
    ind = len(cycles)
    cycles.append(cycle)
    for fr in cycle:
        cands[fr] = ind
        count[fr] = l - 1 - len(friends[fr])


for _ in range(k):
    a, b = map(lambda x: int(x)-1, input().split())
    if a in cycles[cands[b]]:
        count[a] -= 1
        count[b] -= 1

for i in count:
    print(i, end=" ")