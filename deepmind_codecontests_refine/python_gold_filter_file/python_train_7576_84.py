n = int(input())
a = list(map(int,input().split()))
 
from fractions import gcd
lcm = a[0]
for i in range(1, n):
    lcm = lcm * a[i] // gcd(lcm, a[i])
 
ans=0
for i in range(n):
    ans+=lcm//a[i]
 
print(ans%(10**9+7))