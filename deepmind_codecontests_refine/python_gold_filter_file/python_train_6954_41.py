h,w=list(map(int,input().split()))
m=[]
for i in range(h):
  mm=[]
  for j in input():
    mm.append(1 if j=="#" else 0)
  m.append(mm)

wl=[[0 for i in range(w)]for j in range(h)]
for i in range(h):
  s=0
  t=0
  while t<w:
    while t<w and m[i][t]==0:
      t+=1
    for j in range(s,t):
      wl[i][j]=t-s
    s=t+1
    t=t+1
mx=0
for i in range(w):
  s=0
  t=0
  while t<h:
    while t<h and m[t][i]==0:
      t+=1
    for j in range(s,t):
      k=wl[j][i]
      if mx<k+t-s:
        mx=k+t-s
    s=t+1
    t=t+1


print(mx-1)
