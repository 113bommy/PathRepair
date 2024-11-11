N,K = map(int,input().split())
P = list(map(lambda x:int(x)-1,input().split()))
C = list(map(int,input().split()))

ans = -float('inf')
for i in range(N):
    visited = set()
    tmp = 0
    for k in range(K):
        if P[i] in visited: break
        tmp += C[P[i]]
        i = P[i]
        visited.add(i)
        ans = max(ans, tmp)
    if tmp < 0: continue
    l = len(visited)
    rem = K-l
    d,m = divmod(rem,l)
    if m==0 and d > 0:
        m = l
        d -= 1
    tmp *= (d+1)
    for k in range(m):
        tmp += C[P[i]]
        i = P[i]
        ans = max(ans, tmp)

print(ans)