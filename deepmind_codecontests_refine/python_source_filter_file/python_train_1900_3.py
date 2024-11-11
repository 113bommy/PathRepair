from collections import *
from bisect import *
from math import *
import sys
input=sys.stdin.readline
t=int(input())
while(t):
    t-=1
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    if(k not in a):
        print("no")
        continue
    if(n==1):
        print("Yes")
        continue
    s=[]
    for i in a:
        if(i<k):
            s.append(-1)
        else:
            s.append(1)
    flag=0
    for i in range(2,len(s)):
        if(sum(s[i-2:i+1])>0 or sum(s[i-2:i])>0):
            flag=1
            break
    if(flag==0):
        print("No")
    else:
        print("YEs")
