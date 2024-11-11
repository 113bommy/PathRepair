n = int(input())
for i in range(1,n):
  if i*(i+1)//2 > n:
    x = i
    y = i*(i+1)//2 - n
    break
for i in range(1,x+1):
  if i != y:
    print(i)