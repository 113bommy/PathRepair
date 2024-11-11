import sys
input=sys.stdin.readline
n,m=map(int,input().split())
from collections import defaultdict
branch=defaultdict(set)
for i in range(m):
    u,v=map(int,input().split())
    branch[u-1]|={v-1}
s,t=map(int,input().split())
s-=1
t-=1
dist=[[float('inf')]*3 for i in range(n)]
check={(s,0)}
dist[s][0]=0
while len(check)>0:
    now,nowd=check.pop()
    for nex in branch[now]:
        if dist[nex][(nowd+1)%3]>dist[now][nowd]+1:
            dist[nex][(nowd+1)%3]=dist[now][nowd]+1
            check|={(nex,(nowd+1)%3)}
if dist[t][0]>10**18:
    print(-1)
else:
    print(dist[t][0]//3)