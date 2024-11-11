
n = int(input())



res = 1
x = 1
while x <= n:
  if res%x != 0:
    res = max(res, (n+x-1)//x)
  x *= 3
print(res)

