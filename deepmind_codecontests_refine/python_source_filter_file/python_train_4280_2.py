n, m = map(int, input().split())
t = [[] for i in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    t[a].append(b)
    t[b].append(a)
    
q, p, s = [0] * (n + 1), [0] * (n + 1), 0
def dfs(a):
    global q, p, s, t
    q[a] = 1
    for b in t[a]:
        if q[b] == 1 and p[a] != b: s += 1
        if not q[b]:
            p[b] = a
            dfs(b)
    q[a] = 2
    
dfs(1)
print('NO' if s > 1 or 0 in q[1: ] else 'FHTAGN!')