import sys
import math
import collections
import heapq
import decimal
input=sys.stdin.readline
n=int(input())
if(n==2):
    print(1)
    print(1,1)
elif(n==3):
    print(0)
    print(2,1,2)
else:
    l=[]
    for i in range(n,2,-4):
        l.append(n-1)
        l.append(n-2)
    if(n%4==0 or n%4==3):
        print(0)
        print(len(l),*l)
    else:
        print(1)
        print(len(l)+1,*l,1)