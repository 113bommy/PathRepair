from fractions import gcd
s=int(input())
t=list(map(int, input().split()))
ans=t[0]
for i in t:
  ans=(ans*i)//gcd(ans,i)
mod=10**9+7
a=0
for j in t:
  a+=ans//j
print(int(a)%mod)