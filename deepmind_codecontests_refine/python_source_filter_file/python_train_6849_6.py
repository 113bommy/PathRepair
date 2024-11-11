h,w,k=map(int,input().split())
x=[list(input()) for i in range(h)]
a=[[1]*w]+[[0]*w for i in range(h)]
n=0
for i in range(1,h+1):
  f=False
  if '#' in x[i-1]:
    n+=1
    for j in range(w):
      if x[i-1][j]=='#':
        if f:
          n+=1
        else:
          f=True
      a[i][j]=n
  else:
    for j in range(w):
      a[i][j]=a[i-1][j]
if '#' not in x[0]:
  c=[1]*w
  for j in range(1,h+1):
    if a[j]!=c:
      for k in range(j-1,0,-1):
        for i in range(w):
          a[k][i]=a[k+1][i]
      break
for i in range(1,h+1):
  print(*a[i]) 