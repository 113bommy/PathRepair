'''
    Auther: ghoshashis545 Ashis Ghosh
    College: jalpaiguri Govt Enggineerin College
    Date:24/05/2020

'''
import sys
from collections import deque,defaultdict as dd 
from bisect import bisect,bisect_left,bisect_right,insort,insort_left,insort_right
from itertools import permutations
from datetime import datetime
from math import ceil,sqrt,log,gcd
def ii():return int(input())
def si():return input()
def mi():return map(int,input().split())
def li():return list(mi())
abc='abcdefghijklmnopqrstuvwxyz'
abd={'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}
mod=1000000007
#mod=998244353
inf = float("inf")
vow=['a','e','i','o','u']
dx,dy=[-1,1,0,0],[0,0,1,-1]
def read():
    tc=0
    if tc:
        input=sys.stdin.readline
    else:
        sys.stdin=open('input1.txt', 'r')
        sys.stdout=open('output1.txt','w')




def func(mid):
    c1=0
    c2=0
    s=0
    for i in range(n):
        if(x[i]>mid):
            c1+=(x[i]-mid)
        if(x[i]<mid):
            c2+=(mid-x[i])
    if(m<(a+r1)):
        s+=min(c1,c2)*m
        if(c1>c2):
            s+=(c1-c2)*r1
        else:
            s+=(c2-c1)*a
    else:
        s=(c1*r1)+c2*a
        # print(s)
    return s

def solve():
    
    global a,r1,m,x,n
    n,a,r1,m=mi()
    x=li()
    mnx=min(x)
    mx=max(x)
    l=mnx
    r=mx
    ans=0
    c=0
    while(l<=r):
        mid=l+(r-l)//2
        if(mid==mnx):
            if(func(mid)<=func(mid+1)):
                ans=mid
                break
            else:
                l=mid+1
        elif(mid==mx):
            if(func(mid)<=func(mid-1)):
                ans=mid
                break
            else:
                r=mid-1
            
        else:
            x0=func(mid)
            x1=func(mid-1)
            x2=func(mid+1)
            if(x0<=x1 and x0<=x2):
                ans=mid
                break
            elif(x1<x2):
                r=mid-1
            else:
                l=mid+1
    #         # print(l,r)
    # print(ans)
    print(func(5))
            


        
    
    
if __name__ =="__main__":
    # read()
    solve()
    