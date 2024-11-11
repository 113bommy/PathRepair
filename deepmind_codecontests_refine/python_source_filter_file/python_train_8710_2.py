import sys
import math


d=["Power","Time","Space","soul","Reality","Mind"]
b=["purple","green","blue","orange","red","yellow"]
u=[0]*6
a=int(input())
for _ in range(a):
    c=input()
    for i in range(6):
        if b[i]==c:
            u[i]=1
print(6-sum(u))
for _ in range(6):
    if u[_]==0:
        print(d[_])
            