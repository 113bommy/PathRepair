from fractions import gcd
mod = 10**9+7
n = int(input())
a = list(map(int,input().split()))
ans = 0
l = 1
for i in a:
    l = l*i//gcd(l,i)
l %= mod
for i in a:
    ans = (ans +l*pow(i,mod-2,mod)) % mod
print(ans)