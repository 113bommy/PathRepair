a = input()
k = int(input())
lo = 0
hi = 0
for x in a:
  if '?' == x:
    lo -= 1
  elif '*' == x:
    lo -= 1
    hi += 1000
  else:
    lo += 1
    hi += 1
if lo > k or hi < k:
  print('Impossible')
else:
  b = []
  y = ''
  for x in a:
    if '?' == x:
      b.pop()
      if lo < k:
        b += y,
        lo += 1
    elif '*' == x:
      b.pop()
      if lo < k:
        b += [y] * (k - lo)
        lo = k
    else:
      b += x,
      y = x
  print(''.join(b))
