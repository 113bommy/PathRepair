from math import*
n=int(input())
mod=1000000007
s=[int(j) for j in input().split()]
ans=1
for i in s:
    ans*=i//gcd(ans,i)
print(sum(ans//i for i in s)%mod)
