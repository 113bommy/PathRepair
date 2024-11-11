from math import factorial as f
n, m, t = map(int, input().split())
ans = 0
for x in range(4, t):
    if x > n or n - x > m or t - x < 0 or m - t + x < 0:
        continue
    ans += f(n) // f(x) // f(n - x) * f(m) // f(t - x) // f(m - t + x)
print(ans)