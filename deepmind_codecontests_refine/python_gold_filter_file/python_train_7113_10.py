import sys
import math
import collections
import heapq
input=sys.stdin.readline
n,k=(int(i) for i in input().split())
le=1
ri=n
if(n==1):
    print(1)
else:
    while(le<ri):
        mid=(le+ri)//2
        c=0
        k1=1
        while(mid//k1>0):
            c+=mid//k1
            k1*=k
        if(c>=n):
            ri=mid
        else:
            le=mid+1
    print(le)