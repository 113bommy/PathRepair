from fractions import gcd
import math
n = int(input())
a = list(map(int, input().split()))
MOD=10**9+7
lcm=1
for i in range(n):
    lcm*=a[i]//gcd(lcm,a[i])
res=0
for i in range(n):
    res+=lcm//a[i]
print(res%MOD)