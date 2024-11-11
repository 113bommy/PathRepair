N=int(input())
P=[tuple(map(int,input().split())) for i in range(N)]
ans=N-1
for i in range(N):
    for j in range(N):
        if i==j:
            continue
        p=P[i][0]-P[j][0]
        q=P[i][1]-P[j][1]
        cost=0
        for k in range(N):
            if (P[k][0]-p,P[k][1]-q) not in P:
                cost+=1
        ans=min(ans,cost)
print(ans)