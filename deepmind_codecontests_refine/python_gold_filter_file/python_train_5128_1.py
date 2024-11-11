import sys
import math
import heapq
import collections
def inputnum():
    return(int(input()))
def inputnums():
    return(map(int,input().split()))
def inputlist():
    return(list(map(int,input().split())))
def inputstring():
    return([x for x in input()])
def inputmatrixchar(rows):
    arr2d = [[j for j in input().strip()] for i in range(rows)] 
    return arr2d
def inputmatrixint(rows):
    arr2d = []
    for _ in range(rows):
        arr2d.append([int(i) for i in input().split()])
    return arr2d

n, k = inputnums()
a = inputlist()

def check(x, cur):
    ans = 0
    for i in range(n):
        if not cur:
            ans += 1 
            cur = 1 
        else:
            if a[i] <= x:
                ans += 1 
                cur = 0
    return ans >= k

def binsearch(lo, hi):
    while lo < hi:
        mid = (lo+hi)//2 
        if check(mid, 0) or check(mid, 1):
            hi = mid 
        else:
            lo = mid + 1 
    return lo

print (binsearch(1, 1000000000))