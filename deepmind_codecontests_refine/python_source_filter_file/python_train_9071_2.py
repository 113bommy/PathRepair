l, r = input().split()
l, r = int(l), int(r)
pl, pr = 60, 60
mod = 10**9+7
while (2**pl > l):
  pl -= 1
while (2**pr > r):
  pr -= 1
if pr == pl:
  a = 1 if pl % 2 == 0 else 2
  for i in range(1 if pl % 2 == 0 else 2, pl, 2):
    a += 2**i
  ans = (r - 2**pl + 1)*(a + r - 2**pl) - (l - 2**pl) * (a + l - 2**pl - 1)
  ans %= mod
  print(ans)
else:
  al = 1 if pl % 2 == 0 else 2
  for i in range(1 if pl % 2 == 0 else 2, pl, 2):
    al += 2**i
  ar = 1 if pr % 2 == 0 else 2
  for i in range(1 if pr % 2 == 0 else 2, pr, 2):
    ar += 2**i
  n = (r - 2**(pr) + 1)
  ans = n * (ar + n - 1)
  ans %= mod
  n = (2**(pl + 1) - 2**(pl))
  ans += n * (al + n - 1)
  n = l - 2**pl
  ans -= n * (al + n - 1)
  ans %= mod
  it = pl + 1
  while it < pr:
    a = 1 if it % 2 == 0 else 2
    for i in range(1 if it % 2 == 0 else 2, it, 2):
      al += 2**i
    n = 2**(it + 1) - 2**it
    ans += n * (a + n - 1)
    ans %= mod
    it += 1
  print(ans)
  