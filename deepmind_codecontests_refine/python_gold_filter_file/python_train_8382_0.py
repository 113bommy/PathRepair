import sys
import bisect
from bisect import bisect_left as lb
input_=lambda: sys.stdin.readline().strip("\r\n")
from math import log
from math import gcd
from math import atan2,acos
from random import randint
sa=lambda :input_()
sb=lambda:int(input_())
sc=lambda:input_().split()
sd=lambda:list(map(int,input_().split()))
se=lambda:float(input_())
sf=lambda:list(input_())
flsh=lambda: sys.stdout.flush()
#sys.setrecursionlimit(10**6)
mod=10**9+7
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
def dfs(root,par):
    if par!=-1:
        dp[root]=dp[par]+1
    for i in range(1,20):
        if kthpar[root][i-1]!=-1:
            kthpar[root][i]=kthpar[kthpar[root][i-1]][i-1]
    for child in gp[root]:
        if child==par:continue
        kthpar[child][0]=root
        dfs(child,root)
def hnbhai():
    n,m=sd()
    a=sd()
    pos=[0]*(n+3)
    left=[0]*(n+3)
    for i in range(1,n+1):
        pos[a[i-1]]=i
        left[a[i-1]]=n+1
    for i in range(m):
        x,y=sd()
        x=pos[x]
        y=pos[y]
        if(x>y):x,y=y,x
        left[x]=min(left[x],y)
    for i in range(n-1,0,-1):
        left[i]=min(left[i],left[i+1])
    #print(left)
    tot=0
    for i in range(1,n+1):
        tot+=left[i]-i
    print(tot)
for _ in range(1):
    hnbhai()
