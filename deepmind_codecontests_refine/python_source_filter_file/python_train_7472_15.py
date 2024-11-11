N = int(input())
As = []
Bs = []

for _ in range(N):
  c = 0
  m = 0
  for s in input():
    if s == '(':
      c += 1
    elif s == ')':
      c -= 1
    m = min(m, c)
  if c >= 0:
    As.append((-m, c - m))
  else:
    Bs.append((-m, c - m))

As.sort(key=lambda x: x[0])
Bs.sort(key=lambda x: x[1], reverse=True)

f = True
c = 0
for (l, r) in As:
  if c < l:
    f = False
    break
  c += r - l
if f:
  for (l, r) in Bs:
    if c < l:
      f = False
      break
  c += r - l

f = f and (c == 0)

if f:
  print('Yes')
else:
  print('No')