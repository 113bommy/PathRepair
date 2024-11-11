from sys import stdin as fin
# fin = open("hcc2016c1.in", "r")

def dfs(v, p):
    global g, used, cnt
    cnt += 1
    used[v] = True
    for u in g[v]:
        if u != p and (used[u] or not dfs(u, v)):
            return False
    return True

n, m = map(int, fin.readline().split())
used = [False] * n
g = [[] for i in range(n)]
for i in range(m):
    v, u = map(int, fin.readline().split())
    v, u = v - 1, u - 1
    g[v].append(u)
    g[u].append(v)
cnt = 0
if not dfs(0, None) or cnt != n:
    print("No")
else:
    print("Yes")