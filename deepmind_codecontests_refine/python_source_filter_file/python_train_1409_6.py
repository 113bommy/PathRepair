from collections import *
C=Counter
a=0
cx=C()
cy=C()
cp=C()
n=int(input())
for i in range(n):
    x,y=map(int,input().split())
    a=cx[x]+cy[y]-cp[(x,y)]
    cx[x]+=1
    cy[y]+=1
    cp[(x,y)]+=1
print(a)