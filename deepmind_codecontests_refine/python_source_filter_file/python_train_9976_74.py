x = int(input())
res = 0

for i in range(x):
  num = i * i
  while num <= x:
    res = max(res, num)
    num *= i

print(res)