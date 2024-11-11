h, w = map(int, input().split())
a=[]
for i in range(h):
  a.append([it == '#' for it in input()])
q=[]
for i in range(h):
  for j in range(w):
    if a[i][j]: q.append((i, j))
cnt = -1
while q:
  cnt += 1
  r = []
  for i, j in q:
    if i > 0 and not a[i-1][j]:
      a[i-1][j]=True
      r += [(i-1, j)]
    if i < h-1 and not a[i+1][j]:
      a[i+1][j]=True
      r += [(i+1, j)]
    ai = a[i]
    if j > 0 and not ai[j-1]:
      ai[j-1]=True
      r += [(i, j-1)]
    if j < w-1 and not ai[j+1]:
      ai[j+1]=True
      r += [(i, j+1)]
  q=r
print(cnt)

