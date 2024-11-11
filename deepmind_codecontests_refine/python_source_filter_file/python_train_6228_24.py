I=lambda:[int(i) for i in input().split()]
n,m,x,y=I()
a=sorted(I())
b=sorted(I())
t=b[-m]
if x<t<=y and sum(1 for i in a if i<=t)>=n:
  print('No War')
else:
  print('War')