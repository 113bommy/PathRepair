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
      
      def get(x):
        n = len(str(x))
        cnt = 0
        for i in range(n,0,-1):
          cnt_num = x-pow(10,i-1) + 1
          cnt += cnt_num*i
          x = pow(10,i-1)-1
        return cnt
    
      x = []
      s = 0
      for i in range(1,100000):
        s += get(i)
        x.append(s)
        if s > 1e9:
          break

      q = ii()
      for i in range(q):
        n = ii()
        idx = bisect_right(x,n)-1
        n -= x[idx]
        if n==0:
          idx += 1
          print(str(idx)[-1])
          continue
        l = 1
        r = idx+1
        while l <= r:
          mid = (l+r)>>1
          if get(mid) <= n:
            ans = mid
            l = mid+1
          else:
            r = mid-1
        n -= get(ans)
        if n == 0:
          print(str(ans)[-1])
        else:
          print(str(ans)[n-1])
        



      

        
        
        







            





    
        








        
if __name__ =="__main__":

    if(file):
    
       if path.exists('input.txt'):
           sys.stdin=open('input.txt', 'r')
           sys.stdout=open('output.txt','w')
       else:
           input=sys.stdin.readline
    solve()
