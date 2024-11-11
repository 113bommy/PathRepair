t = int(input())
for tt in range(t):
  a = input()
  ans = 1000000000
  g = 1
  for i in range(64):
    s = str(g)
    p = 0
    for j in a:
      if p < len(s) and j == s[p]:
        p += 1
    cans = len(s) - p + len(a) - p
    ans = min(ans, cans)
    g *= 2
  print(ans)