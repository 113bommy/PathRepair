'''
    Auther: ghoshashis545 Ashis Ghosh
    College: jalpaiguri Govt Enggineering College
    Date:10/06/2020

'''
from os import path
import sys
from functools import cmp_to_key as ctk
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

def bo(i):
    return ord(i)-ord('a')

def isprime(n):
    for i in range(2,int(sqrt(n))+1):
        if n%i==0:
            return 0
    return 1
def solve():
    
    # for _ in range(ii()):
        
        
        
    n=ii()
    a=li()
    ans=0
    pre=[1]*n
    c=1
    for i in range(1,n):
        if(a[i]<=a[i-1]):
            c=1
        else:
            c+=1
        pre[i]=c            
            
    suff=[1]*n
    c=1
    for i in range(n-2,-1,-1):
        if a[i]>=a[i+1]:
            c=1
        else:
            c+=1
        suff[i]=c
    ans=max(ans,suff[0])
    for i in range(1,n-1):
        ans=max(ans,pre[i])
        x=pre[i]-1
        if a[i-1]<a[i+1]:
            x+=suff[i+1]
        ans=max(ans,suff[i])
        ans=max(ans,x)
    ans=max(ans,pre[n-1])
    print(ans)
        
        
        
        
        
if __name__ =="__main__":
    solve()
