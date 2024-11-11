import sys
sys.setrecursionlimit(10**7)
input=sys.stdin.readline
def dfs(v,p):
    if res_v[v]!=-1:
        return res_v[v]
    size[v]=len(G[v])
    dp[v]=[0]*size[v]
    res=1
    for i in range(size[v]):
        nv=G[v][i]
        if nv==p:
            p_i[v]=i
            continue
        R=dfs(nv,v)
        dp[v][i]=R
        res=res*(R+1)%MOD
    return res
    
def reroot(v,res_p,p):
    if p!=-1:
        dp[v][p_i[v]]=res_p
    for i in range(size[v]):
        ans[v]=ans[v]*(dp[v][i]+1)%MOD
    dp_L=[1]*(size[v]+1)
    dp_R=[1]*(size[v]+1)
    for i in range(size[v]):
        dp_L[i+1]=dp_L[i]*(dp[v][i]+1)%MOD
    for i in reversed(range(size[v])):
        dp_R[i]=dp_R[i+1]*(dp[v][i]+1)%MOD
        
    for i in range(size[v]):
        nv=G[v][i]
        if nv==p:
            continue
        reroot(nv,dp_L[i]*dp_R[i+1]%MOD,v)

N,MOD=map(int,input().split())
G=[[] for i in range(N)]
for i in range(N-1):
    x,y=map(lambda x:int(x)-1,input().split())
    G[x].append(y)
    G[y].append(x)
res_v=[-1]*N
dp=[[] for i in range(N)]
size=[-1]*N
p_i=[-1]*N
dp_L=[[] for i in range(N)]
dp_R=[[] for i in range(N)]
ans=[1]*N

z_root=dfs(0,-1)
res_v[0]=z_root
reroot(0,0,-1)
print(*ans,sep='\n')