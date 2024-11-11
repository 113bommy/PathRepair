import sys
sys.setrecursionlimit(10**7)
M=10**9+7
N=10**6
fac=[0]*(N+1)
fac[0]=b=1
for i in range(1,N+1):fac[i]=b=b*i%M
inv=[0]*(N+1)
inv[N]=b=pow(fac[N],M-2,M)
for i in range(N,0,-1):inv[i-1]=b=b*i%M
def dfs1(v,p):
    s=1
    l=[]
    c1,c2=[1],[1]
    for w in e[v]:
        if w==p:continue
        l+=w,
        dfs1(w,v)
        u=sz1[w]
        c1+=c1[-1]*dp1[w]*inv[u]%M,
        s+=u
    for w in l[::-1]:
        c2+=c2[-1]*dp1[w]*inv[sz1[w]]%M,
    e[v]=l
    c[v]=c1,c2[::-1]
    sz1[v]=s
    dp1[v]=c1[-1]*fac[s-1]%M
n,*t=open(0).read().split()
n=int(n)
e=[[]for _ in range(n)]
for a,b in zip(*[map(int,t)]*2):
    e[a-1]+=b-1,
    e[b-1]+=a-1,
sz1,sz2=[0]*n,[0]*n
dp1,dp2=[0]*n,[0]*n
c=[[]for _ in range(n)]
dfs1(0,-1)
# print(dp1)
sz2[0]=1
dp2[0]=1
s=[0]
while s:
    v=s.pop()
    l=len(e[v])
    c1,c2=c[v]
    uv=sz2[v]-1
    tv=dp2[v]*inv[uv]
    for i,w in enumerate(e[v]):
        tw=c1[i]*c2[i+1]%M
        uw=uv+sz1[v]-sz1[w]-1
        dp2[w]=tv*tw*fac[uw]%M
        sz2[w]=uw+2
        s+=w,
# print(dp2)
for i in range(n):
    u1=sz1[i]-1
    u2=sz2[i]-1
    print(dp1[i]*dp2[i]*inv[u1]*inv[u2]*fac[u1+u2]%M)