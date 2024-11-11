def calc(x, y, k):
  s = k * (y + 1) - 1
  p = x - 1
  if s % p == 0:
    return int(s // p) + k
  else: return int(s / p + k + 1)

for i in range(int(input())):
  x, y, k = map(int, input().split(' '))
  print(calc(x, y ,k))
  








  