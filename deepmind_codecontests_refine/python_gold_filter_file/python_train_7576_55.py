from fractions import gcd
n = int(input())
a = list(map(int, input().split()))
lcm = 1
for i in range(n):
    lcm = a[i] * lcm // gcd(a[i], lcm)
b = [lcm // a[i] for i in range(n)]
print(sum(b) % (10**9+7))