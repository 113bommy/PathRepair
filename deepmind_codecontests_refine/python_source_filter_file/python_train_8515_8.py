n,k=map(int,input().split())
s=input()
from itertools import groupby
a=[len(list(j)) for i,j in groupby(s)]
if s[0]==0:
  a=[0]+a
if s[n-1]==0:
  a=a+[0]
w=2*k+1
if len(a)<=w:
  print(n)
  exit()
m=sum(a[:w])
x=m
for i in range(2,len(a)-2*k,2):
  m=m-a[i-1]-a[i-2]+a[i+k+1]+a[i+k+2]
  x=max(x,m)
print(x)