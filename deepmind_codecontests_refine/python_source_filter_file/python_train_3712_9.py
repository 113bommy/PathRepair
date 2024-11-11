#n junctions m roads 
#start at s and finish at t 
n,m,s,t=map(int,input().split())
from collections import defaultdict 
d=defaultdict(list)
for i in range(m):
    a,b=map(int,input().split())
    a-=1 
    b-=1 
    d[a].append(b)
    d[b].append(a)
def calc(d,s,t):
   # print(d)
    dist=[10**9]*n 
    vis=[0]*n 
    q=[s]
    #q[s]=1 
    dist[s]=0 
    vis[s]=1 
    while q:
        t=q.pop(0)
        for i in d[t]:
            if not vis[i]:
                dist[i]=dist[t]+1 
                vis[i]=1 
                q.append(i)
    return dist 
s-=1 
t-=1
dist_s=calc(d,s,t)
dist_t=calc(d,t,t)
#print(dist_s,dist_d)
ans=0 

mini=dist_s[t]
s,t=min(s,t),max(s,t)
#print(mini)
for i in range(n):
    for j in range(i+1,n):
        if i not in d[j] and not (i==s and j==t) : 
            #effect of adding an edge b/n i and j 
            psbl1=dist_s[i]+1+dist_t[j]
            psbl2=dist_t[i]+1+dist_s[j]
            m=min(psbl1,psbl2)
            if m>=mini:
                print(i,j)
                ans+=1 
print(ans)