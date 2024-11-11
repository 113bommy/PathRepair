from math import gcd

n = int(input())
a = [tuple(map(int, input().split())) for i in range(n)]

ans = 0
for x,y in a:
    ans = gcd(x*y,ans)

for x, y in a:
    if gcd(ans, x) > 1:
        res = gcd(ans, x)
    else:
        res = gcd(ans, y)

print(-1 if ans == 1 else res)