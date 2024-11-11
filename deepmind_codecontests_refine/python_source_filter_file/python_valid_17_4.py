
from math import ceil, gcd, inf, sqrt
from bisect import bisect_left
from collections import Counter
import sys
mod=1000000007

def pro(arr):
    n=len(arr)
    if(n==1):
        print(1)
        return
    cand=0
    for i in range(1,n):
        c=0
        for j in range(5):
            if(arr[i][j]<arr[cand][j]):
                c+=1
        if(c>=3):
            cand=i
    cou=0
    for i in range(n):
        if(i!=j):
            c=0
            for j in range(5):
                if(arr[cand][j]<arr[i][j]):
                    c+=1
            if(c>=3):
                cou+=1
    print(cand+1 if cou==n-1 else -1)
t=int(input())
for i in range(t):
    n=int(input())
    arr=[]
    for j in range(n):
        arr.append ( list(map(int,input().split())) )
    pro(arr)