n, *a = map(int, open(0).read().split())
res = 1
if 0 in a:
  print(0)
  exit()
for a in a:
  res *= a
  if res >= 1e18:
    res = -1
    break
print(res)