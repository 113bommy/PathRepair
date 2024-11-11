n = int(input())
ans = 0
d = { 'JPY': 1, 'BTC': 380000.0}
for _ in range(n):
  a, b = input().split()
  ans += int(a) * d[b]
print(ans)