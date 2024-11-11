import sys
input=sys.stdin.buffer.readline
n=int(input())
l=list(map(int,input().split()))
f=1
from fractions import gcd

for i in l:
    f=f*i//gcd(f,i)
mod=10**9+7
ans=0
for i in l:
  ans+=f//i
print(ans%mod)
