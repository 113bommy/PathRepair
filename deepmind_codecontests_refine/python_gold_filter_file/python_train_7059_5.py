h,w=map(int,input().split())
l=[[0]*w]*h
m=[""]*h
for k in range(h):
  m[k]=input()
l[0][0]=1
for k in range(h):
  for j in range(w):
    if m[k][j]=="#":
      l[k][j]=0
    else:
      if k==0:
        if j!=0:
          l[k][j]=l[0][j-1]
      elif j==0:
        if k!=0:
          l[k][j]=l[k-1][j]
      else:
        l[k][j]=l[k-1][j]+l[k][j-1]
print(l[h-1][w-1]%1000000007)
