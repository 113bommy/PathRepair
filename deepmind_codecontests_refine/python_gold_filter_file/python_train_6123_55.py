import sys
sys.setrecursionlimit(10**6)
MOD=10**9+7
def dfs(v,p):
    if seen[v]:
        return dp[v]
    seen[v]=1
    b,w=1,1
    for nv in G[v]:
        if(nv==p):
            continue
        bw=dfs(nv,v)
        w*=sum(bw);w%=MOD
        b*=bw[1];b%=MOD
    dp[v]=(b,w)
    return (b,w)
    
N=int(input())
G,dp,seen=[],[],[]
for i in range(N):
    G.append([]);dp.append([0,0]);seen.append(0)
for i in range(N-1):
    x,y=map(lambda x:int(x)-1,input().split())
    G[x].append(y)
    G[y].append(x)
print(sum(dfs(0,-1))%MOD)