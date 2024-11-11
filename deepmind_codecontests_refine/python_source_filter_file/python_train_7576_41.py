
from fractions import gcd


n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
x = a[0]
for i in range(1, len(a)):
    x = (x * a[i]) // gcd(x, a[i])
gcd=x
res = 0
for i in a:
    res += gcd//i
    res%=mod
print(res)

