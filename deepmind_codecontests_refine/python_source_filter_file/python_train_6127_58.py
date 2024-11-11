n, m = map(int, input().split())

if m <= 2 * n:
  ans = n
else:
  ans = n + (m - 2 * n) // 4

print(ans)