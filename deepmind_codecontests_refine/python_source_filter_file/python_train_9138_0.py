n=int(input())
gg=[input() for _ in [0]*n]
graph=[[] for _ in [0]*n]


inf=10**10
dist=[[inf for _ in [0]*n] for _ in [0]*n]

for i in range(n):
    dist[i][i]=0
    for j in range(n):
        if gg[i][j]=="1":
            graph[i].append(j)
            dist[i][j]=1
            dist[j][i]=1
q=[0]
dp=[0]*n
dp[0]=1


flag=True
while q:
    i=q.pop()
    for j in graph[i]:
        if dp[j]==0:
            dp[j]=dp[i]*(-1)
            q.append(j)
        elif dp[j]==dp[i]:
            flag=False
            break
    if flag==False:
        break

        

if flag==False:
    print(-1)
else:
    for k in range(n):
        for i in range(n):
            for j in range(n):dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]))
    print(max([max([i for i in j]) for j in dist])+1)
