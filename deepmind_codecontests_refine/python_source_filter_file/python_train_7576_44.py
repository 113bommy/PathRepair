from math import gcd
n = int(input())
a = list(map(int, input().split()))
l = 1
for x in a:
    l = l * x // gcd(l, x)
ans = 0
for x in a:
    ans += l // x
print(ans % (10 ** 9 + 7))
