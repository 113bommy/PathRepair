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
b=[]

def dfs2(root,par,d):
    global gp,dp
    dp[root]=d
    for child in gp[root]:
        if child==par:continue
        dfs2(child,root,d+1)
def hnbhai(tc):
    x1,y1,x2,y2=sd()
    a,b=sd()
    x=abs(x1-x2)
    y=abs(y1-y2)
    if x%a!=0 or y%b!=0:
        print("NO")
        return
    x=x//a
    y=y//b
    #print(x,y)
    if abs(x-y)%2!=0:
        print("NO")
        return
    print("YES")
for _ in range(1):
    hnbhai(_+1)
