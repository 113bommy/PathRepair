def gcd(a, b): return gcd(b % a, a) if a else b
n = int(input())
a = sorted(map(int, input().split()))
p, q = 0, n
for i in range(1, n): p += i * (n - i) * (a[i] - a[i - 1])
p = 2 * p + sum(a)
r = gcd(p, q)
print(p // r, q // r)
