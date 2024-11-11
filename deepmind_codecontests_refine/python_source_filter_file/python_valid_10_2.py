import sys
import bisect
from bisect import bisect_left as lb
from bisect import bisect_right as rb
input_=lambda: sys.stdin.readline().strip("\r\n")
from math import log
from math import gcd
from math import atan2,acos
from random import randint
sa=lambda :input_()
sb=lambda:int(input_())
sc=lambda:input_().split()
sd=lambda:list(map(int,input_().split()))
sflo=lambda:list(map(float,input_().split()))
se=lambda:float(input_())
sf=lambda:list(input_())
flsh=lambda: sys.stdout.flush()
#sys.setrecursionlimit(10**6)
mod=10**9+7
mod1=998244353
gp=[]
cost=[]
dp=[]
mx=[]
ans1=[]
ans2=[]
special=[]
specnode=[]
a=0
kthpar=[]
def dfs2(root,par):
    if par!=-1:
        dp[root]=dp[par]+1
    for i in range(1,20):
        if kthpar[root][i-1]!=-1:
            kthpar[root][i]=kthpar[kthpar[root][i-1]][i-1]
    for child in gp[root]:
        if child==par:continue
        kthpar[child][0]=root
        dfs(child,root)
        
ans=0
b=[]
vis=[]
tot=0
time=[]
time1=[]
adj=[]
mx=-1
def dfs(a,b,p,c):
    if a==b:
        return c
    for i,j in adj[a]:
        if i==p:continue
        temp=dfs(i,b,a,c+j)
        if dfs(i,b,a):
            mx=max(i,mx)
            return 1
eps=0.0000009
def hnbhai(tc):
    n,k=sd()
    s=sd()
    d={}
    for i in s:
        d[i]=d.get(i,0)+1
    store={}
    for i in range(n):
        if store.get(s[i]) is None:
            store[s[i]]=[i]
        else:
            store[s[i]].append(i)
    temp=[]
    ans=[0]*n
    for i in store:
        t=store[i]
        t=[len(t)]+t
        temp.append(t)
    temp.sort(reverse=True)
    abe=[]
    tt=0
    for i in range(len(temp)):
        t=temp[i][1:]
        tot=0
        for j in t:
            abe.append([j,tt])
            if len(abe)==k:
                for a in abe:
                    ans[a[0]]=a[1]
                abe=[]
            tt+=1
            tot+=1
            if tt>k:
                tt=1
            if tot==k:
                break
    print(*ans)
def dfs(root):
    global tot,vis,gp
    for child in gp[root]:
        if vis[child]==0:
            tot+=1
            vis[child]=1
            dfs(child)
for _ in range(sb()):
    hnbhai(_+1)
