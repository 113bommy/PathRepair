n,a,b,c=map(int,input().strip().split(' '))
s=n%4
if s==0:
  print(0)
elif s==3:
  print(min(a,3*c,c+b))
elif s==2:
  print(min(b,2*a,2*c))

else:
  print(min(c,3*a,b+a))