import sys
from math import *
input=sys.stdin.readline
n,a,b,k=map(int,input().split())
c=0
aa=[int(x) for x in input().split()]
d=[]
for i in range(n):
    p=aa[i]%(a+b)
    
    if p<=a and p!=0:
        c+=1
    elif p>a:
        p-=a
        d.append(int(ceil(p/a)))
    elif p==0 :
        d.append(int(ceil(b/a)))
    else:
        c+=1
d.sort() 

for i in d:
    if k-i<0:
        break
    k-=i
    c+=1
    
print(c)        