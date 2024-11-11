n = int(input())
s = []
for i in range(n):
  s.append(input())

ls = []
rs = []
tot = 0
for si in s:
  b = 0
  h = 0
  for c in si:
    if c == '(':
      h += 1
    else:
      h -= 1
    b = min(h,b)
  if h > 0:
    ls.append((b,h))
  else:
    rs.append((b-h,-h))
  tot += h
ls.sort(reverse = True)
rs.sort(reverse = True)

def check(x):
  t = 0
  for bx,hx in x:
    if t+bx < 0:
      return False
    t += hx
  return True

if check(ls) and check(rs) and tot == 0:
  print('Yes')
else:
  print('No')
