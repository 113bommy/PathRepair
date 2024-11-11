k=input()
a,b=input().split()
c=int(a)
d=int(b)
l=int(k)
e=d-d%l
if e>=c:
  print('ok')
else:
  print('ng')