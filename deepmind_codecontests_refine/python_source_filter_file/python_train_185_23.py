N, P = map(int, input().split())
if N >= 40:
  print(1)
else:
  m = int(P**(1/N))
  while True:
    if P % m == 0:
      x = m**N
      if P % x == 0:
        break
    m -= 1
  print(m)