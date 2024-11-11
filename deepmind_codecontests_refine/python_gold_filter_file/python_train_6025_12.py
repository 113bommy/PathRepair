n,l,*a=map(int,open(0).read().split())
i=m=0
for j,(x,y)in enumerate(zip(a,a[1:]),1):
  if x+y>m:
    m=x+y
    i=j
if m<l:
  print('Impossible')
else:
  print('Possible')
  print(*range(1,i))
  print(*range(n-1,i,-1))
  print(i)