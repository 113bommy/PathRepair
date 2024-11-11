import sys
input = sys.stdin.readline

N,M,S=map(int,input().split())
E=[[] for i in range(N+1)]
for i in range(M):
    u,v,a,b=map(int,input().split())
    E[u].append((v,a,b))
    E[v].append((u,a,b))

C=[(0,0)]+[tuple(map(int,input().split())) for i in range(N)]
DP=[[1<<30]*5001 for i in range(51)]

import heapq

Q=[(0,min(S,5000),1)]
DP[1][min(S,5000)]=0

while Q:
    time,money,town = heapq.heappop(Q)

    for to,pmoney,ptime in E[town]:
        if money>=pmoney and DP[to][money-pmoney]>time+ptime:
            DP[to][money-pmoney]=time+ptime
            heapq.heappush(Q,(time+ptime,money-pmoney,to))
            
    if DP[town][min(money+C[town][0],5000)]>time+C[town][1]:
        DP[town][min(money+C[town][0],5000)]=time+C[town][1]
        heapq.heappush(Q,(time+C[town][1],min(money+C[town][0],5000),town))
        
for i in range(2,N+1):
    print(min(DP[i]))

