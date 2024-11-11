n, m = map(int, input().split())
ab = sorted([ list(map(int, input().split())) for _ in range(n) ])
c = 0
for a, b in ab:
  if n <= b:
    c += a*n
    print(c)
    break
  else:
    c += a*b
    n -= b