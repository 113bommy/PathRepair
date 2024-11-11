import math
from collections import defaultdict
def r():
    return int(input())
def rm():
    return map(int,input().split())
def rl():
    return list(map(int,input().split()))

'''A Cut ribbon'''
n,a,b,c=rm()
d=[a,b,c]
d.sort()
a,b,c=d
cnt=0
for i in range(0,n):
    for j in range(0,n):
        k=n-(i*a+j*b)
        if k>=0 and k%c==0:
            cnt=max(cnt,i+j+k//c)
print(cnt)
