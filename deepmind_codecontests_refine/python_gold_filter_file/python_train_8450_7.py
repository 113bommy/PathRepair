'''
    Auther: ghoshashis545 Ashis Ghosh
    College: jalpaiguri Govt Enggineering College
    Date:09/06/2020

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

    

    
    
    
    
def solve():
    
    
    
        
    n=ii()
    s=si()
    lsum,rsum=0,0
    lcnt,rcnt=0,0
    for i in range(n//2):
        if s[i]=='?':
            lcnt+=1
        else:
            lsum+=ord(s[i])-48
    for i in range(n//2,n):
        if s[i]=='?':
            rcnt+=1
        else:
            rsum+=ord(s[i])-48
    
    maxr1=rsum+ceil(rcnt/2)*9
    maxr2=lsum+ceil(lcnt/2)*9
    # print(maxr1,maxr2)
    if(maxr2==maxr1):
        print("Bicarp")
    else:
        print("Monocarp")
            
            
            
            
            
            
            
            
            
            
    
    
    
    
    
    
    
if __name__ =="__main__":
    solve()
