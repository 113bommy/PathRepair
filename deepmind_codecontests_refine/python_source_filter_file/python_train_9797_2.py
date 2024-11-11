import math
n,k = map(int,input().split())
if n<=(2*k+1):
    print(1)
    print(math.ceil(n/2))
    exit()
x=(math.ceil(n/(2*k+1)))
k1=n%(2*k+1);ans=[]
if k1==0 and k1<k+1 :
  print(x);l=2*k+1
  for i in range(1,n+1,l):
      print(i,end=" ")
else:
  print(x);l=2*k+1
  for i in range(k+1,n,l):print(i,end=" ")
  
