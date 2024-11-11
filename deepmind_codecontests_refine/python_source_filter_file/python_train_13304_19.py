l,r=map(int,input().split())
if r-l>=2019:
  print(0)
else:
  a=float("inf")
  for i in range(l,r+1):
    for j in range(l+1,r+1):
      a=min(i*j%2019,a)
  print(a)
