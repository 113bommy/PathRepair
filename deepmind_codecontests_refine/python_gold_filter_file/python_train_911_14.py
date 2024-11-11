cin = open(0).read().strip().split('\n')
n = int(cin[0])
p = list(map(int, cin[1].split(' ')))

space = [1]*(n*n)

dist = [0]*(n*n)
for r in range(n):
    for c in range(n):
        dist[r*n+c] = min(r, (n-1)-r, c, (n-1)-c)

ans = 0
for pi in p:
    pi -= 1
    q = [pi]
    ans += dist[pi]
    space[pi] = 0

    while q:
        pp = q.pop()
        for dxi in [-n,-1,1,n]:
            if dxi == 1 and pp % n==n-1: continue
            if dxi == -1 and pp % n ==n: continue
            if 0<=pp+dxi<n*n and dist[pp+dxi] > dist[pp]+space[pp]:
                q.append(pp+dxi)
                dist[pp+dxi] = dist[pp]+space[pp]

print(ans)