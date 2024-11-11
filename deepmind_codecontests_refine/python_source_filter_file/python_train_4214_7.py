n=int(input())
a=sorted([int(input()) for _ in range(n)])
b=None

if n==0: 
  b=[1,1,3,3]
elif n==1: 
  x=a
  b=[x,x*3,x*3]
elif n==2: 
  x,y=a
  if x==y: b=[x*3,x*3]
  elif x*3>=y: b=[x*3,x*4-y]
elif n==3:
  x,y,z=a
  if x*3>=z and x*4==y+z: b=[x*3]
  elif z+z/3==x+y: b=[z//3]
  elif z==x*3: b=[x*4-y]
elif n==4:
  x,y,z,v=a
  if v==x*3 and x*4==y+z: b=[]

if b != None:
  print('YES')
  for x in b: print(x)
else:
  print('NO')
