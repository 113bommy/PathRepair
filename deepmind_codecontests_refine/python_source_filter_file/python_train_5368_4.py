from collections import defaultdict
n,m,k=map(int,input().split())
graph=defaultdict(list)
for i in range(m):
    u,v,w=map(int,input().split())
    graph[u].append([v,w])
    graph[v].append([u,w])
if(k==0):
    print(-1)
else:
    storage=list(map(int,input().split()))
    myMap=defaultdict(int)
    for val in storage:
        myMap[val]=1
    ans=float("-inf")
    for i in range(1,n+1):
        size=len(graph[i])
        if(myMap[i] and size>0):
            for j in range(size):
                if(myMap[graph[i][j][0]]==0 and graph[i][j][1]<ans):
                    ans=graph[i][j][1]
    if ans!=float("-inf"):
        print(ans)
    else:
        print(-1)