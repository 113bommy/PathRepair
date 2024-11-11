import sys
input = sys.stdin.readline
from collections import Counter
h,w,n=map(int,input().split())
c=Counter()
for _ in range(n):
    a,b=map(int,input().split())
    for i in [-1,0,1]:
        for j in [-1,0,1]:
            if 2<=a+i<w and 2<=b+j<h:
                c[a+i,b+j]+=1
#print(c.items())
c2=Counter(c.values())
print((h-2)*(w-2)-sum(c2.values()))
for i in range(1,10):
    print(c2[i])
