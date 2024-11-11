x=int(input())

d=-(-x//11)
r=x%11
if 1<=r<=6:
  print(2*d-1)
else:
  print(2*d)