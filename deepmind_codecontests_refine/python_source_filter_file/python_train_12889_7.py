N,W=map(int,input().split())
WV=[list(map(int,input().split())) for i in range(N)]
V=10**3

DP_V=[float("inf")]*(V*N+1)
DP_V[0]=0
for i in range(N):
    for j in range(V*N,-1,-1):
        if j+WV[i][1]<V*N-1:
            DP_V[j+WV[i][1]]=min(DP_V[j+WV[i][1]],DP_V[j]+WV[i][0])

for i in range(V*N,-1,-1):
    if DP_V[i]<=W:
        print(i)
        break