import bisect
A, B, Q = map(int, input().split())
inf = 10**18
lisS = [-inf] + [int(input(x)) for x in range(A)] + [inf]
lisT = [-inf] + [int(input(x)) for x in range(B)] + [inf]
for _ in range(Q):
  x = int(input())
  i = bisect.bisect_right(lisS, x)
  j = bisect.bisect_right(lisT, x)
  res = inf
  for S in [lisS[i - 1], lisS[i]]:
    for T in [lisT[j - 1], lisT[j]]:
      r1 = abs(S - x) + abs(S - T)
      r2 = abs(T - x) + abs(S - T)
      res = min(res, r1, r2)
  print(res)