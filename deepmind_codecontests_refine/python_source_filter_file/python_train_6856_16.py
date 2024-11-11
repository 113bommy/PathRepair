n = int(input())
num = 1
while num * (num + 1) <= 2 * n:
  num += 1
now = n
for i in range(num,0,-1):
  if now >= i:
    print(i)
    now -= i