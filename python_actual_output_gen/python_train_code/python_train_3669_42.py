n, k, t = map(int, input().split())
if t <= k:
  print(t)
elif t > n:
  print(k - n + k)
else:
  print(k)