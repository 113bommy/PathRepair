k, a, b = map(int, input().split())
if a >= k:
  print(1)
else:
  if a <= b:
    print(-1)
  else:
    r = (k-a) // (a-b)
    print(2*r+1)