n,a,b,c,d=map(int,input().split())
a,b=min(a,b),max(a,b)
pl1=b-d
pr1=b-c
pl2=b+c
pr2=b+d
flag=False
for i in range((n-2)//2+1):
  j=(n-2)-i*2
  al=j*c+i*(c-d)
  ar=j*d+i*(d-c)
  if (al<pl1 and pl1<=ar) or pl1<=al<=pr1:
    flag=True
    break
  if (al<pl2 and pl2<=ar) or pl2<=al<=pr2:
    flag=True
    break
if flag==True:
  print('YES')
else:
  print('NO')