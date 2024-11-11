import math
n, k = map(int, input().split())
p = 0
for i in range(1,n+1):
  temp = 1
  while i * temp < k:
    temp *= 2
  p += 1/temp
print(p/n)