from math import *
n,k=map(int,input().split())
e=0
for i in range(1,n+1):
  t=ceil(log2(k/i))
  e+=1*(m<1)or 2**-t
print(e/n)