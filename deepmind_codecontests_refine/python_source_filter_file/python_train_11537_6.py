import bisect

A, B, Q = map(int, input().split())

INF = 10 ** 18
s = [-INF] + [int(input()) for _ in range(A)] + [INF]
t = [-INF] + [int(input()) for _ in range(B)] + [INF]

for i in range(Q):
  x = int(input())
  b = bisect.bisect_right(s, x)
  d = bisect.bisect_right(t, x)
  dist = 0
  for sb in [s[b - 1], s[b]]:
    for td in [t[d - 1], t[d]]:
      d1, d2 = abs(x - sb) + abs(sb - td), abs(x - td) + abs(td - sb)
      dist = min(dist, d1, d2)
  print(dist)