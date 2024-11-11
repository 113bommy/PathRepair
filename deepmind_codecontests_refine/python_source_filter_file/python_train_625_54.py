a,b,c = map(int, input().split())
x = 0
for i in range(a,b+1):
 if c % i == 0:
  x += x+1
 print(x)

