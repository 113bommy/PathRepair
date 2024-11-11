import math
n, m, t = map(int, input().split())

C = lambda n, k: math.factorial(n) / math.factorial(k) / math.factorial(n-k)

ans = 0
for boys in range(4, t):
    girls = t - boys
    if boys <= n and girls <= m:
      ans += C(n, boys) * C(m, girls)

print(int(ans))