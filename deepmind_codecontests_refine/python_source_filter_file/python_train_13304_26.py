l,r=map(int,input().split())
if r-l>=2019:
  print(0)
else:
  a=2019
  for i in range(l,r):
    for j in range(i+1,r+1):
      a=min((i%2019)*(j%2019)%2019,a)
print(a)
