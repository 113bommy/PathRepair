from collections import*
n, m, *t = map(int, open("test").read().split())       
*w, s, t = [a-1for a in t]         
e = [[]for _ in range(n)]        
for u, v in zip(w[::2], w[1::2]):      
    e[u].append(v)

INF = 10**10
f = [[INF]*3for _ in range(n)]        
f[s][0] = 0        
q = deque([(s, 0)])           
while q:
    vi, j = q.popleft()         
    if vi == t and j == 0:
        print(f[vi][0]//3)
        break
    for ui in e[vi]:           
        if f[ui][(j+1)%3] < INF: continue           
        f[ui][(j+1)%3] = f[vi][j] + 1
        q.append((ui, (j+1)%3))
else:
    print(-1)