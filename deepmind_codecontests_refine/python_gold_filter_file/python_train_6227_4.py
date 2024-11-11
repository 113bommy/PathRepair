n, m = map(int, input().split())
ab = sorted([ list(map(int, input().split())) for _ in range(n) ])
c = 0
for a, b in ab:
  if m <= b:
    c += a*m
    print(c)
    break
  else:
    c += a*b
    m -= b