x = int(input())
res = 1

for i in range(2, x):
  num = i * i
  while num <= x:
    res = max(res, num)
    num *= i
    
print(res)