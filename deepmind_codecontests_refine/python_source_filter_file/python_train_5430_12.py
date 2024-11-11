import sys
import math
import collections
import heapq
input=sys.stdin.readline
n,m=(int(i) for i in input().split())
l=[int(i) for i in input().split()]
le=-1
ri=m
while(le<ri-1):
    mid=(le+ri)//2
    prev=0
    c=1
    for i in range(n):
        if((m-l[i]+prev)%m>mid):
            if(i<prev):
                c=0
                break
            else:
                prev=l[i]
    if(c==0):
        le=mid
    else:
        ri=mid
print(ri)