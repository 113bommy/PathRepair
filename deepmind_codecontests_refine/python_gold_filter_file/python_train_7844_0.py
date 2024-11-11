'''
    Auther: ghoshashis545 Ashis Ghosh
    College: Jalpaiguri Govt Enggineering College

'''
from os import path
from io import BytesIO, IOBase
import sys
from heapq import heappush,heappop
from functools import cmp_to_key as ctk
from collections import deque,Counter,defaultdict as dd 
from bisect import bisect,bisect_left,bisect_right,insort,insort_left,insort_right
from itertools import permutations
from datetime import datetime
from math import ceil,sqrt,log,gcd
def ii():return int(input())
def si():return input().rstrip()
def mi():return map(int,input().split())
def li():return list(mi())
abc='abcdefghijklmnopqrstuvwxyz'
mod=1000000007
#mod=998244353
inf = float("inf")
vow=['a','e','i','o','u']
dx,dy=[-1,1,0,0],[0,0,1,-1]

def bo(i):
    return ord(i)-ord('0')

file = 1
def ceil(a,b):
    return (a+b-1)//b




def solve():

    
    # for _ in range(1,ii()+1):
      
    n = ii()
    a = li()
    if n == 1 or n%2==0:
      print('-1')
      return

    cnt = 0
    for i in range(n//2-1,-1,-1):
      x = max(a[2*i+1],a[2*i+2])
      cnt += x
      a[i] = max(0,a[i]-x)

    print(cnt + a[0])








            





    
        








        
if __name__ =="__main__":

    if(file):
    
       if path.exists('input.txt'):
           sys.stdin=open('input.txt', 'r')
           sys.stdout=open('output.txt','w')
       else:
           input=sys.stdin.readline
    solve()
