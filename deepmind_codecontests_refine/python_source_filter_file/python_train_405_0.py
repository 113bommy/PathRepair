import itertools

while True:
  n, k, s = map(int, input().split())
  if n + k + s == 0:
    break

  a = itertools.combinations(range(n + 1), k)

  ans = 0

  for e in a:
    if sum(e) != s:
      continue
    ans += 1

  print(ans)  