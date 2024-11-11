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
from math import sqrt,log,gcd
def ii():return int(input())
def si():return input().rstrip()
def mi():return map(int,input().split())
def li():return list(mi())
def ceil(a,b): return (a+b-1)//b
abc='abcdefghijklmnopqrstuvwxyz'
mod=1000000007
# mod=998244353
inf = float("inf")
vow=['a','e','i','o','u']
dx,dy=[-1,1,0,0],[0,0,1,-1]

def bo(i):
    return ord(i)-ord('a')


test = 0
def solve():

    # int( str(i)+x[i] ) is divisible by 7
    x = ['1869','6198','1896','1689','1986','1968','8691']
    freq = [0]*10
    s = si()
    for i in s:
        freq[int(i)] +=1

    freq[1] -= 1
    freq[6] -= 1
    freq[8] -= 1
    freq[9] -= 1

    res = ""
    cur = 0
    for i in range(1,10):
        for j in range(freq[i]):
            cur *= 10
            cur += i
            cur %= 7
    for i in range(1,9):
        print(str(i)*freq[i],end="")
    print(x[cur],end="")
    
    print('0'*freq[i])


    
    
        



          
if __name__ =="__main__":

   
    if path.exists('input.txt'):
        sys.stdin=open('input.txt', 'r')
        sys.stdout=open('output.txt','w')
    else:
        input=sys.stdin.readline

    t = 1
    if test:
        t = ii()

    for _ in range(t):

        solve()