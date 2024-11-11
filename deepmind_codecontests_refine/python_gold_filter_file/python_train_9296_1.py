'''
    Auther: ghoshashis545 Ashis Ghosh
    College: jalpaiguri Govt Enggineering College

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


    # for _ in range(ii()):

    n,k = mi()
    a = li()

    # replace all the element which is greater or equal to x by +1 and other element by -1.
    # then we need to find such a subarray of length greater than or equal to k which sum is greater than 0.

    def check(x):
        c = [0]*n
        for i in range(n):
            if a[i] >= x:
                c[i] = 1
            else:
                c[i] = -1
        for i in range(1,n):
            c[i] += c[i-1]

        if c[k-1] > 0:
            return True
        mnx = 0
        for i in range(k,n):
            mnx = min(mnx,c[i-k])
            if c[i] > mnx:
                return True
        return False




    l = 1
    r = n
    while l <= r:
        mid = (l+r)>>1
        if check(mid):
            ans = mid
            l = mid+1
        else:
            r = mid-1
    print(ans)
        
        







            





    
        








        
if __name__ =="__main__":

    if(file):

        if path.exists('tmp/input.txt'):
            sys.stdin=open('tmp/input.txt', 'r')
            sys.stdout=open('tmp/output.txt','w')
        else:
            input=sys.stdin.readline
    solve()
