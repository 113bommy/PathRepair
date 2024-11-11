from fractions import gcd
n = int(input())
a = [int(i) for i in input().split()]

b = 1
for i in a:
    b = b * i // gcd(b, i)

ans = 0
for i in a:
    ans += b // i

print(ans%(10**9+7))
