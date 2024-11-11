input = __import__("sys").stdin.readline

n, m = map(int, input().split())

e = [[] for i in range(n+1)]
for i in range(m):
    u, v = map(int, input().split())
    
    e[u].append(v)
    e[v].append(u)

sol = 0
used = [False for i in range(n+1)]
for i in range(1, n):
    if used[i]:
        continue
    
    cc = []
    
    q = [i]
    used[i] = True

    while len(q):
        u = q.pop()
        cc.append(u)
        
        for v in e[u]:
            if not used[v]:
                q.append(v)
                used[v] = True
    
    ce = 0
    for u in cc:
        ce += len(e[u]) == 2
    
    if ce == len(cc):
        sol += 1

print(sol)

