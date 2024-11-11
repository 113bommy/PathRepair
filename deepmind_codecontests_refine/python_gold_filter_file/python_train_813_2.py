h,w=map(int,input().split())
s=[list(input().replace(".","0")) for i in range(h)]
for i in range(h):
  for j in range(w):
    if s[i][j]=="#":
      for k in range(-1,2):
        for l in range(-1,2):
          if 0<=i+k<h and 0<=j+l<w and s[i+k][j+l]!="#":
              s[i+k][j+l]=str(int(s[i+k][j+l])+1)
for i in range(h):
  for j in range(w):
    print(s[i][j], end="")
  print()