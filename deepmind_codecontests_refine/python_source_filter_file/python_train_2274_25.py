from math import gcd
n, k = map(int, input().split())
a = list(map(int, input().split()))

x = a[0]
for i in range(1, n):
    x = gcd(x, a[i])

print("POSSIBLE" if k % x == 0 and max(a) >= k else "IMPOSSIBLE")
