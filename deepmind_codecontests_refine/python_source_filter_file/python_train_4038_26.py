M,N,X=map(int,input().split())
C=[list(map(int,input().split())) for i in range(N)]
INF=float("inf")
ans=INF

for i in range(1,2**N):
    skills=[0]*M
    total_cost=0
    for j in range(N):
        if ((i>>j)&1):
            total_cost+=C[j][0]
            for k in range(M):
                skills[k]+=C[j][k+1]
    if min(skills)>=X:
        ans=min(ans,total_cost)
        
print(ans if ans != INF else -1)