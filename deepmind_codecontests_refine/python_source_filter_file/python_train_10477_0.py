import sys


def prepare():
    stack = [i for i in range(n) if deg[i] == 0]
    cnt = 0
    while stack:
        v = stack.pop()
        cnt += 1
        for dest in adj[v]:
            deg[dest] -= 1
            if deg[dest] == 0:
                stack.append(dest)
        adj[v].clear()

    return cnt == n


def solve(st):
    stack = [st]
    visited = [0]*500
    cnt = 0
    while stack:
        v = stack.pop()
        cnt += 1
        for dest in adj[v]:
            if dest == st:
                continue
            visited[dest] += 1
            if deg[dest] == visited[dest]:
                stack.append(dest)

    return cnt == n


n, m = map(int, sys.stdin.buffer.readline().decode('utf-8').split())
adj = [[] for _ in range(n)]
rev = [[] for _ in range(n)]
deg = [0]*n
for u, v in (map(int, line.decode('utf-8').split()) for line in sys.stdin.buffer):
    adj[u-1].append(v-1)
    rev[v-1].append(u-1)
    deg[v-1] += 1

ok = prepare()
if ok:
    print('YES')
    exit()

n = len([1 for i in range(n) if deg[i] > 0])
for i in range(n):
    if deg[i] == 1 and solve(i):
        print('YES')
        exit()

print('NO')
