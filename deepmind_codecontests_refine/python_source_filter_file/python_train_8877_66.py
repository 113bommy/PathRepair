import sys
import bisect as bi
import math
from collections import defaultdict as dd
import queue 
##import heapq
##import itertools
##import io
##import os
##import operator
input=sys.stdin.readline
##input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
##import random
##sys.setrecursionlimit(10**7)
##fo=open("output2.txt","w")
##fi=open("input2.txt","w")
mo=10**9+7
def cin():return map(int,sin().split())
def ain():return list(map(int,sin().split()))
def sin():return input().strip()
def inin():return int(input())

#-----------------------------------------------------------------------------------------------------------------------#

for  _ in range(inin()):
        a,b,c,d=cin()
        print(max(a,d)+min(b,c))
        
                
        
        
        
        
  
                
                
            

            
    
#-----------------------------------------------------------------------------------------------------------------------#
##def msb(n):n|=n>>1;n|=n>>2;n|=n>>4;n|=n>>8;n|=n>>16;n|=n>>32;n|=n>>64;return n-(n>>1) #2 ki power
##def pref(a,n,f):
##    pre=[0]*n
##    if(f==0):         ##from beginning
##        pre[0]=a[0]
##        for i in range(1,n):
##            pre[i]=a[i]+pre[i-1]
##    else:              ##from end
##        pre[-1]=a[-1]
##        for i in range(n-2,-1,-1):
##            pre[i]=pre[i+1]+a[i]
##    return pre
##maxint=10**24
##def kadane(a,size):
##    max_so_far = -maxint - 1
##    max_ending_here = 0
##
##    for i in range(0, size):
##        max_ending_here = max_ending_here + a[i]
##        if (max_so_far < max_ending_here):
##            max_so_far = max_ending_here
##
##        if max_ending_here < 0:
##            max_ending_here = 0
##    return max_so_far
##def modFact(n, p):
##    if(n<0):return 0
##    if n >= p: return 0
##    result = 1
##    for i in range(1, n + 1):result = (result * i) % p
##    return result
##def ncr(n, r, p):
##    if(n<r or n<0): return 0
##    num = den = 1 
##    for i in range(r): 
##        num = (num * (n - i)) % p ;den = (den * (i + 1)) % p 
##    return (num * pow(den,p - 2, p)) % p 
