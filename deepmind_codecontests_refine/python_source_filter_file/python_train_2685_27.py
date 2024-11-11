from fractions import gcd
from math import ceil
n,m=map(int,input().split())
a=list(map(int,input().split()))
c=len(bin(a[0]))-bin(a[0]).rfind("1")
for i in range(1,n):
  if c!=len(bin(a[i+1]))-bin(a[i+1]).rfind("1"):
    print(0)
    exit()
g=a[0]
for i in range(n-1):
   g=(g//gcd(g,a[i+1]))*(a[i+1]//gcd(g,a[i+1]))*gcd(g,a[i+1])
g//=2
print(ceil((m//g)/2))
