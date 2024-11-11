h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
b=a
for i in range(h):
  for j in range(w):
    if a[i][j]!="#":
      b[i][j]=a[i][max(0,j-1):min(w,j+2)].count("#")
      if i!=0:
        b[i][j]+=a[i-1][max(0,j-1):min(w,j+2)].count("#")
      if i!=h-1:
        b[i][j]+=a[i+1][max(0,j-1):min(w,j+2)].count("#")
for i in range(h):
  print("".join(str(j) for j in b[i]))