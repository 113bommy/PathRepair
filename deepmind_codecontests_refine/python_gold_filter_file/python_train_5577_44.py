s=[int(n) for n in input().split()]
n=s[0]
a=s[1]
b=s[2]
c=s[3]
d=n%4
j=[]
u=0
if d==0:
  u=1
  print(0)
elif d==1:
  j=[3*a,c,a+b]
elif d==2:
  j=[b,2*a,2*c,3*b]
elif d==3:
  j=[a,b+c,3*c]
if u==0:
  print(min(j))