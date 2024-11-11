x = int(input())
m = 1
b = 2
while b*b <= x:
  p = 2
  while b**p <= x:
    m = max(m, b**p)
    p += 1
  b += 1
  