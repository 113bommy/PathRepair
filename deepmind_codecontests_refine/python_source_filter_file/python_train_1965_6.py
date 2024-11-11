import sys
m=166666;s=[1]*m;t=[1]*m
for i in range(m):
 for j in range(2):
  if (s[i],t[i])[j]:
   k=6*i+[5,7][j];n=[i+k,k-i-2]
   s[n[i]::k]=[0]*len(s[n[i]::k])
   t[n[1-i]::k]=[0]*len(t[n[1-i]::k])
for e in map(int,sys.stdin):
 print([e-1,sum(s[:(e+1)//6])+sum(t[:(e-1)//6])+2)[e>3])
