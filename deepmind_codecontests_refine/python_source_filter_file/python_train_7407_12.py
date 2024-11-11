from collections import defaultdict
x=int(input())
dp=[0]*(x+1)
vis=[1]*(x+1)
def dfs(x,d):
    vis[x]=0
    if len(d[x])>0:
        for i in d[x]:
            if vis[i]:
                dfs(i,d)
            print(dp)    
            dp[x]=max(dp[x],1+dp[i])    
    

d=defaultdict(list)
for i in range(x):
    a=int(input())
    d[a].append(i+1)
p=list(d.keys())
p.remove(-1)
for i in p:
    if vis[i]:
        dfs(i,d)
print(max(dp)+1)        