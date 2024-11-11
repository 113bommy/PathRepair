m = int(input())
ans = 0
sum_d = 0
for i in range(m):
  a, b = map(int, input().split())
  ans += b
  sum_d += a * b
print(ans + sum_d // 10 - 1)