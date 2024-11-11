'''
    Auther: ghoshashis545 Ashis Ghosh
    College: jalpaiguri Govt Enggineering College

'''
from os import path
import sys
from heapq import heappush,heappop
from functools import cmp_to_key as ctk
from collections import deque,defaultdict as dd 
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
# mod=998244353
inf = float("inf")
vow=['a','e','i','o','u']
dx,dy=[-1,1,0,0],[0,0,1,-1]

def bo(i):
    return ord(i)-ord('a')

file = 1



def solve():


    

    # for _ in range(ii()):
        n,c = mi()
        stairs = li()
        elevator = li()
        ans = [[2,0] for i in range(n)]
        res = [0]*n
        for i in range(1,n):
            ans[i][0] = min(ans[i-1][0] + elevator[i-1] , ans[i-1][1] + elevator[i-1]+c)
            ans[i][1] = min(ans[i-1]) + stairs[i-1]
            res[i] = min(ans[i])
        print(*res)









    
        
if __name__ =="__main__":

    if(file):

        if path.exists('input.txt'):
            sys.stdin=open('input.txt', 'r')
            sys.stdout=open('output.txt','w')
        else:
            input=sys.stdin.readline
    solve()
