import math


INF = 10 ** 9 + 7


n = int(input())
res = 1
p = 1
for i in range(1, n + 1):
  res = res * i % INF
for i in range(1, n):
  p = p * 2 % INF
print(res - p)
