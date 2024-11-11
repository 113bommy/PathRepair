N,K = map(int, input().split())
P = [[int(p) for p in input().split()] for _ in range(N)]

P.sort()

ans = 10**20
for i in range(N-K+1):
    X = P[i+K-1][0]
    x = P[i][0]
    Y = []
    for j in range(i, K+i):
        Y.append(P[j][1])
    Y.sort()
    ans = min(ans, (X-x)*(Y[-1]-Y[0]))
    for j in range(K+i, N):
        Y.append(P[j][1])
        Y.sort()
        for k in range(len(Y)-K+1):
            ans = min(ans, (P[j][0]-x)*(Y[k+K-1]-Y[k]))
            
print(ans)