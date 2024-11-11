from  functools import reduce
from  math import gcd
n,m=map(int,input().split())
a=list(map(int,input().split()))
a=[i//2 for i in a]
#print(a)
lc=reduce(lambda x,y: (x*y)//gcd(x,y) , a)
#print(lc)
flag=True
for i in a:
  if (lc//i)%2==0:
    flag=False
    break
if flag==False:
  print(0)
else:
  x=m//lc
  print(x//2) if (x%2)==0 else print((x//2)+1)
