from itertools import accumulate as ac
s=input()
n=len(s)
mod=int(1e9)+7

*aca,=ac([0]+[1 if i=="A" else 0 for i in s])
*acc,=ac([0]+[1 if i=="C" else 0 for i in s])
*acq,=ac([0]+[1 if i=="?" else 0 for i in s])

v=0
for i in range(1,n-1):
  if s[i]=="B" or s[i]=="?":
    a=aca[i]
    l=acq[i]
    c=acc[n]-acc[i+1]
    r=acq[n]-acq[i+1]
    v+=(a*c*pow(3,l+r,mod))
    if l+r-1>=0:
      v+=(a*r*pow(3,l+r-1,mod))+(l*c*pow(3,l+r-1,mod))
    if l+r-2>=0:
      v+=(l*r*pow(3,l+r-2,mod))
    v%=mod