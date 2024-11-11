T = int(input())

for t in range(T):
  x, y, p, q = map(int, input().split())
  if p == q and x != y:
      print(-1)
      continue

  INF = 10000000000
  lb = -1
  ub = INF
  mod_y = (q - y % q) % q

  while ub - lb > 1:
    mid = (ub + lb) // 2
    diff = mod_y + q * mid
    bunbo = y + diff
    bunshi = p * bunbo // q
    if bunshi >= x and bunshi - x <= diff:
      ub = mid
    else:
      lb = mid
  if ub == INF:
    print(-1)
  else:
    print(mod_y + q * ub)