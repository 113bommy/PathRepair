h,w,m = map(int,input().split())
b = []
x = [0 for _ in range(w)]
y = [0 for _ in range(h)]
for i in range(m):
  bh,bw = map(int,input().split())
  bh -= 1
  bw -= 1
  b.append((bh,bw))
  x[bw] += 1
  y[bh] += 1
#print(b,x,y)

mxx = max(x)
mxy = max(y)

cmxb = 0
for by,bx in b:
  if y[by]+x[bx] == mxx+mxy-1:
    cmxb += 1
cmxx = 0
for xi in x:
  if xi == mxx:
    cmxx += 1
cmxy = 0
for yi in y:
  if yi == mxy:
    cmxy += 1
#print(cmxb,cmxx,cmxy)

if cmxb >= cmxx*cmxy:
  print(mxx+mxy-1)
else:
  print(mxx+mxy)