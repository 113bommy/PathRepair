n,m,*t = map(int, open(0).read().split())
ans = 0
for a, b in sorted(zip(t[::2], t[1::2])):
  ans += min(a, m)*b
  m -= a
  if m <= 0:
    print(ans)
    break;