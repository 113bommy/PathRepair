from math import sqrt
n,m=map(int,input().split())
mini=max(n-(2*m),0)
dn=0.5+(0.5*sqrt(1+8*m))
idn=int(dn)
mm=(2*idn-1)**2
maxi=idn+(mm!=m)
if m is 1 or m==2:
      maxi=m+1
maxi=n-maxi
if m is 0:
      maxi=n
print(mini,maxi)
