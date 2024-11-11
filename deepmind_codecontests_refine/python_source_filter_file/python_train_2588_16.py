from collections import defaultdict as de
from collections import Counter as C
h,w,n=map(int,input().split())
s=[0]*10
c=de(int)
for i in range(n):
    a,b=map(int,input().split())
    for j in range(max(2,a-1),min(a+2,h)):
        for q in range(max(2,b-1),min(b+2,w)):
            c[(j,q)]+=1
a=C(c.values())
print((h-8)*(w-8)-sum(a.values()))
for i in range(1,10):
    print(a[i])