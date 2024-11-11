import sys
import math
from collections import defaultdict,Counter

# input=sys.stdin.readline
# def print(x):
#     sys.stdout.write(str(x)+"\n")

# sys.stdout=open("CP2/output.txt",'w')
# sys.stdin=open("CP2/input.txt",'r')

# m=pow(10,9)+7
t=int(input())
for i in range(t):
    n,m,k=map(int,input().split())
    a=list(map(int,input().split()))
    r=n-k
    r1=m-k-1
    ans2=0
    r2=n-m+1
    if r1>0:
        for j in range(k+1):
            a1=a[j:j+r]
            # print(a1)
            x=0
            ans1=1000000000
            for kk in range(r1+1):
                # a2=a1[kk:kk+r2]
                # print(a2)
                x=max(a1[kk],a1[kk+r2-1])
                ans1=min(ans1,x)
            ans2=max(ans2,ans1)
    else:
        for j in range(m):
            a1=a[j:j+r2]
            # print(a1)
            ans2=max(a1[0],a1[-1])
    print(ans2)