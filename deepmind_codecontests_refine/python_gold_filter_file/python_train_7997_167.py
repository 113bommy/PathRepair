from fractions import gcd
x, y = map(int, input().split())
if gcd(x,y) == y:
  print(-1)
else:
  print((y-1)*x)