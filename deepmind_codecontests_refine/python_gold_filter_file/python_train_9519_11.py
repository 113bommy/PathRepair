c, d = map(int, input().split())
n, m = map(int, input().split())
k = int(input())
total = n * m - k
if k >= n * m:
  print(0)
elif c < d:
  if total % n == 0:
    print(((total // n)) * c)
  else:
    print(((total // n) + 1) * c)
else:
  nr = 0
  nn = (c / n)
  nm = d
  if nn < nm:
    #while (nr * n) + n < total:
    #  nr += 1
    nr = total // n
    npn = nr * c
    if nr * n < total:
      npn = (nr + 1) * c
    npm = nr * c + d * (total - nr * n)
    print(min(npn, npm))
  else:
    print(d * total)
