x, k, d = map(int, input().split())
x = abs(x)
a = x // d
if a >= k:
  print(x - d * k)
elif (k - a) % 2:
  print(d * (a + 1) - a)
else:
  print(a - d * a)
