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

def ceil(a,b):
    return (a+b-1)//b
file=1

def f():
    sys.stdout.flush()


def func(p1,q1):

    ans = []
    for i in range(1,q1+1):
        ans.append(p1**i)
    return ans


def solve():

    for _ in range(ii()):
   
        n = ii()
        n1 = n
        cntdivisor = 1
        divisor = []
        for i in range(2,int(sqrt(n))+1):
            c = 0
            while(n%i==0):
                c +=1
                n //=i
            if c > 0:
                cntdivisor *= (c+1)
                divisor.append([i,c])
        if n>1:
            divisor.append([n,1])
            cntdivisor *= 2
        
        print(divisor)
        # eliminant 1
        ans = func(divisor[0][0],divisor[0][1])
        n = len(divisor)
        # print(ans)
        for i in range(1,n):
            p = divisor[i][0]
            q =divisor[i][1]
            tmp = func(p,q)
            n = len(ans)
            lcm = p*ans[-1]
            ans.append(lcm)
            ans += tmp[1:]
            for j in range(n):
                for k in tmp:
                    if k*ans[j] == lcm:
                        continue
                    if k*ans[j]==n1 and n>2:
                        continue
                    ans.append(k*ans[j])
            ans.append(p)



        if len(divisor)==2:
            if len(ans)==3:
                print(*ans)
                print(1)
            else:
                ans[-2],ans[-1] = ans[-1],ans[-2]
                print(*ans)
                print(0)
        elif len(divisor) == 1:
            print(*ans)
            print(0)
        else:
            ans.append(n1)
            print(*ans)
            print(0)















        
if __name__ =="__main__":

   
    if path.exists('input.txt'):
        sys.stdin=open('input.txt', 'r')
        sys.stdout=open('output.txt','w')
    else:
        input=sys.stdin.readline
    solve()
    