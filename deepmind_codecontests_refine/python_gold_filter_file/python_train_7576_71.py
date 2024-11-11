from fractions import gcd
def lcm(a,b):
    return a*b // gcd(a,b)

N = int(input())
A = list(map(int,input().split()))
M = 10**9+7
l = 1
for a in A:
    l = lcm(l,a)
ans = 0
for a in A:
    ans += l//a
print(ans%M)
