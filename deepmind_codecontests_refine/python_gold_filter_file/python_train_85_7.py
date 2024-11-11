n, m = map(int, input().split())
p = [list(map(int, input().split())) for i in range(n + m)]
for a, b in p[:n]:
  x = [abs(a - c) + abs(b - d) for c, d in p[n:]]
  print(x.index(min(x)) + 1)