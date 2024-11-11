import sys
sys.setrecursionlimit(10**7)
input=sys.stdin.readline
MOD=10**9+7

def facinv(N):
    fac,finv,inv=[0]*(N+1),[0]*(N+1),[0]*(N+1)
    fac[0]=1;fac[1]=1;finv[0]=1;finv[1]=1;inv[1]=1
    for i in range(2,N+1):
        fac[i]=fac[i-1]*i%MOD
        inv[i]=MOD-inv[MOD%i]*(MOD//i)%MOD
        finv[i]=finv[i-1]*inv[i]%MOD
    return fac,finv,inv

def dfs(v,p):
    connect[v]=len(G[v])
    dp[v]=[1]*connect[v]
    sizdp[v]=[0]*connect[v]
    for i in range(connect[v]):
        nv=G[v][i]
        if nv==p:
            p_i[v]=i
            continue
        R,siz=dfs(nv,v)
        dp[v][i]=R
        size[v]+=siz
        sizdp[v][i]=siz
    res=fac[size[v]-1]
    for i in range(connect[v]):
        if G[v][i]==p:
            continue
        res=res*dp[v][i]%MOD*finv[sizdp[v][i]]%MOD
    return res,size[v]
    
def reroot(v,res_p,p):
    if p!=-1:
        dp[v][p_i[v]]=res_p
        sizdp[v][p_i[v]]=N-size[v]
    ans[v]=fac[N-1]
    for i in range(connect[v]):
        ans[v]=ans[v]*dp[v][i]%MOD*finv[sizdp[v][i]]%MOD
    dp_L=[1]*(connect[v]+1)
    dp_R=[1]*(connect[v]+1)
    for i in range(connect[v]):
        dp_L[i+1]=dp_L[i]*dp[v][i]%MOD*finv[sizdp[v][i]]%MOD
    for i in reversed(range(connect[v])):
        dp_R[i]=dp_R[i+1]*dp[v][i]%MOD*finv[sizdp[v][i]]%MOD
        
    for i in range(connect[v]):
        nv=G[v][i]
        if nv==p:
            continue

        reroot(nv,fac[N-size[nv]-1]*dp_L[i]*dp_R[i+1]%MOD,v)


N=int(input())
fac,finv,inv=facinv(N)
G=[[] for i in range(N)]
for i in range(N-1):
    x,y=map(lambda x:int(x)-1,input().split())
    G[x].append(y)
    G[y].append(x)
dp=[[] for i in range(N)]
sizdp=[[] for i in range(N)]
connect=[-1]*N
size=[1]*N
p_i=[-1]*N
dp_L=[[] for i in range(N)]
dp_R=[[] for i in range(N)]
ans=[1]*N
dfs(0,-1)
reroot(0,1,-1)
print(*ans,sep='\n')