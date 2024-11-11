h,w,m=map(int,input().split())
l=[list(map(int,input().split())) for i in range(m)]
H=[0]*h
W=[0]*w
for i in range(m):
  H[l[i][0]-1]+=1
  W[l[i][1]-1]+=1
hmax=max(H)
wmax=max(W)
cthmax=0
ctwmax=0
for i in range(h):
  if H[i]==hmax:
    cthmax+=1
for i in range(w):
  if W[i]==wmax:
    ctwmax+=1
ct=0
for i in range(m):
  if H[l[i][0]-1]==hmax and W[l[i][1]-1]==wmax:
    ct+=1
if cthmax*ctwmax>ct:
  print(hmax+wmax)
else:
  print(hmax+wmax-1)