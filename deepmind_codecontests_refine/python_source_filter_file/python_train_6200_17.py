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
sflo=lambda:list(map(float,input_().split()))
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
ans=0
def hnbhai(tc):
    n=sb()
    a=sd()
    d={}
    ans=0
    for i in range(n):
        for j in range(30):
            if d.get((1<<j)-a[i]):
                ans+=d[(1<<j)-a[i]]
        d[a[i]]=d.get(a[i],0)+1
    print(ans)
for _ in range(1):
    hnbhai(_+1)
