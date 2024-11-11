z=input
import math
n=int(input())
c=1
l=list((map(int,z().split())))
p=[]
for i in l:
    if i%2==0:
        p.append(i-1)
    else:
        p.append(i)
print(*p)
    
