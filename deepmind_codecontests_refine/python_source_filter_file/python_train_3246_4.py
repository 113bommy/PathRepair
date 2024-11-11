import math
n,k=map(int,input().split())
a=[0]*(k+1)
b=math.ceil(n/2)
l=0
d=0
for i in range(n):
    c=int(input())
    a[c]+=1
    if a[c]==2:
        d+=2
        l+=1
        a[c]-=2
        if l==b:
            break
if l>=b:
    print(d)
else:
    print(d+k-l)