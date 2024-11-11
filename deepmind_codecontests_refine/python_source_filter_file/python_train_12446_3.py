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
    a1,b1,a2,b2,l,r=sd()
    if b1<l:
        b1-=((b1-l)//a1)*a1
    if b2<l:
        b2-=((b2-l)//a2)*a2
    lcm=a1*a2
    lcm//=gcd(a1,a2)
    mx=min(r+1,lcm+max(b1,b2))
    while b1!=b2 and mx>b1:
        if b1>b2:
            b2-=((b2-b1)//a2)*a2
        else:
            b1-=((b1-b2)//a1)*a1
    if mx>b1:
        print(1+(r-b1)//lcm)
        return
    print(-1)
for _ in range(1):
    hnbhai(_+1)
