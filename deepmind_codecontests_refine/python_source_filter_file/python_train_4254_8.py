N,M = map(int,input().split())

G = [[] for i in range(N)]

for i in range(M) :
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

ans = "NO" if any(len(g) for g in G) else "YES"

print(ans)
