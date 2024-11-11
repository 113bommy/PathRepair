from math import *
from bisect import *
s=input()
t=input()
n=len(s)
nn=len(t)
ss=[[]for i in range(26)]
tt=[[] for i in range(26)]
ans=0
k=0
for i in range(n):
    ss[ord(s[i])-97].append(i+1)
for i in t:
    j=ss[ord(i)-97]
    if len(j)==0:
        print(-1)
        exit()
    else:
        if j[-1]<=ans:
            ans=j[0]
            k+=1
        else:
            ans=j[bisect(j,ans)]
print(k*n+ans)