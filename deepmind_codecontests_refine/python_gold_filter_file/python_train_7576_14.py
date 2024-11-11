from fractions import gcd

n=int(input())
a=list(map(int, input().split()))
mod=10**9+7
l=1
ans=0

for i in a:
    l=l*i//gcd(l,i)

for i in a:
    ans+=l//i

print(ans%mod)