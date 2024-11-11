n, t = map(int, input().split())
x = 10**(n - 1)
r = x % t
x += (t - r) % x
if len(str(x)) != n:
  print(-1)
else:
  print(x)