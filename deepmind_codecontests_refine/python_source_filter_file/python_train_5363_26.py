from math import ceil


n, p, q = map(int, input().split())
s = input()

if p == n or q == n:
  print(f'1\n{s}')
else:
  if p > q:
    p, q = q, p

  P = ceil(n/p)
  Q = ceil(n/q)
  cnts = [-1, -1]
  i = P
  while i > 0:
    _sum = p*i
    j = 0
    while j < Q and _sum < n:
      _sum += q
      j += 1

    if _sum == n:
      cnts = [i, j]
      break

    i -= 1

  if _sum == n:
    cnts = [i, j]
    
  if cnts[0] == -1:
    print(-1)
  else:
    print(sum(cnts))
    _i = 0
    for i in range(cnts[0]):
      print(s[_i:_i+p])
      _i += p
    for j in range(cnts[1]):
      print(s[_i:_i+q])
      _i += q
