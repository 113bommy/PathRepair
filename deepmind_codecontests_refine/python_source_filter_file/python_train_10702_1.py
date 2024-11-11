N=int(input())
mod=10**9+7
X=[-1]*N
for i,a in enumerate(map(int,input().split())):
    if i==0:
        X[0]=a
    else:
        X[i]=X[i-1]^a
if X[-1]>0:
    x=X[-1]
    dp0=1
    dp1=0
    zero=0
    for i in range(N):
        if X[i]==x:
            dp0=(dp0+dp1*zero)%mod
            zero=0
            dp1=(dp1+dp0)%mod
        elif X[i]==0:
            zero+=1
        
    print(dp0)
    exit()
from collections import defaultdict
dp0=defaultdict(lambda :1)
dp1=defaultdict(int)
zero=defaultdict(int)
zeronow=0
for i in range(N-1):
    x=X[i]
    if x>0:
        dp0[x]=(dp0[x]+dp1[x]*(zeronow-zero[x]))%mod
        zero[x]=zeronow
        dp1[x]=(dp1[x]+dp0[x])%mod
    elif x==0:
        zeronow+=1

print(sum(dp1.values())+pow(2,zeronow,mod))