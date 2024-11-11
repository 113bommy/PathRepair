import sys
input=sys.stdin.readline
from collections import Counter
m=int(input())
p=list(map(int,input().split()))
mod=10**9+7
cnt=Counter(p)
ans=x=1
for k in cnt.values():
    x*=k+1
for a,b in cnt.items():
    q=(x*b//2)%(mod-2)
    ans=(ans*pow(a,q,mod))%mod
print(ans)