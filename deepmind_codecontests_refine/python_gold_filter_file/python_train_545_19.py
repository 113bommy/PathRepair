import sys

# input = sys.stdin.readline
ll = lambda: list(map(int, input().split()))
lls = lambda: list(map(str, input().split()))
fin = lambda: list(map(float, input().split()))
st = lambda: input()
v = lambda: map(int, input().split())
ii = lambda: int(input())
mod = (10 ** 9) + 7
from math import *
# from fractions import *
from datetime import datetime
from collections import *
import math
# print(log(8,3))
x=ii()
l=ll()
if(x<3):
    if(x==1):
        print(1,1)
        l[0]+=1
        print(1)
        print(1,1)
        l[0]+=1
        print(1)
        print(1,1)
        print(-l[0])
    else:
        print(1, 1)
        print(-l[0])
        if(l[1]%2):
            print(2,2)
            print(1)
            l[1]+=1
            print(2,2)
            print(-l[1])
        else:
            print(2,2)
            print(0)
            print(2,2)
            print(-l[1])
elif(x==3):
    print(1,1)
    print(-l[0])
    print(2,2)
    print(-l[1])
    print(3,3)
    print(-l[2])
else:
    #print(l)
    print(x,x)
    print(-l[-1])
    l[-1]=0
    print(1,x-1)
    sol=[]
    for i in range(x-1):
        sol.append((x-1)*(((l[i]%x)+x)%x))
        l[i]+=sol[i]
    print(*sol)
    print(1,x)
    ans=[]
    #print(l)
    for i in range(x):
        ans.append(-l[i])
    print(*ans)





