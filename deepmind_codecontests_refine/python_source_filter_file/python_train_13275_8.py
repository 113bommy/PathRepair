n=int(input())

if n < 0:
  n = 360 - abs(n)%360

n %= 360


if n == 315:
  print(0)
  exit(0)

r = 0
while n > 45:
  r += 1
  n-=90

print(r)