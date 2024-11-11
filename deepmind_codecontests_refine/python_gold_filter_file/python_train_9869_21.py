from fractions import gcd

a, b = map(int, input().split())
d = gcd(a, b)

ans = 1
n = d
for i in range(2, d + 1):
    if n % i == 0:
        ans += 1
        while n % i == 0:
            n //= i
    if n < i * i:
        if 1 < n:
            ans += 1
        break
print(ans)