from fractions import gcd
from math import sqrt
a,s=map(int,input().split())
f=gcd(a,s)
ans=1
if f<=3:print(1+(f!=1));exit()
for i in range(2,int(sqrt(f))+1):

  if f%i==0:
    ans+=1
    while f%i==0:f//=i
print(ans+(f!=1))
