from fraction import gcd
n = int(input())

ans = 1
for i in range(n):
    t = int(input())
    ans = ans * t // gcd(ans, t)

print(ans)