from fractions import *
a,b=map(int,input().split())
g=gcd(a,b)
l=[g]
for i in range(2,int(g**.5)+1):
  if g%i<1: l+=[i,g//i]
c=1
for i in sorted(l):
  if g<2: break
  if g%i<1: c+=1
  while g%i<1: g//=i
print(c)