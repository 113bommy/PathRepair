m, n = map(int, input().split())
k = min(m, n); x = max(m, n); s = 0
for i in range(1, k + 1):
  s += (i % 5 + x) // 5
print(s)