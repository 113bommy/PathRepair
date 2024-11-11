import sys
import math
import collections
import heapq
import decimal
input=sys.stdin.readline
n=int(input())
l=[]
for i in range(n):
    a,b=(int(i) for i in input().split())
    l.append((a,b,i+1))
l1=[]
for i in range(n):
    l1.append(l[i])
l1.sort()
ind=-1
le=l1[0][0]
ri=l1[0][1]
k=l1[0][2]
for i in range(1,n):
    if(l1[i][0]<=le and l1[i][1]>=ri):
        ind=k
        break
    elif(l1[i][1]<=ri):
        ind=l[i][2]
        break
    else:
        le=max(ri+1,l1[i][0])
        ri=l1[i][1]
        k=l1[i][2]
print(ind)