randid = 'dtojbc'
n,m,stx,sty = map(int, input().split())
print(stx, sty)
cx = stx
lvx = stx
for cy in range(1, n + 1):
  jx = cx
  while cx <= m:
    if cx != stx or cy != sty: print(cx, cy)
    cx += 1
  if cx >= m: cx = m
  if jx > 1:
    cx = jx - 1
    while cx > 0:
      if cx != stx or cy != sty: print(cx, cy)
      cx -= 1
    cx = 1