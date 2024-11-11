from collections import defaultdict as dd
import math
import sys
input=sys.stdin.readline
def nn():
    return int(input())
 
def li():
    return list(input())
 
def mi():
    return map(int, input().split())
 
def lm():
    return list(map(int, input().split()))
 
 
 
def solve():
    n ,k= mi()
    nums = lm()
    
    left = []
    right = []
    for num in nums:
        if num<0:
            left.append(num)
        else:
            right.append(num)
    left.sort()
    right.sort()
    dist = 0
    i=0
    while k*i<len(left):
        dist+=-2*left[k*i]
        i+=1
    i=0
    while k*i<len(right):
        dist+=2 * right[-k*i-1]
        i+=1
    if len(left)==0:
        dist -= right[-1]
    elif len(right)==0:
        dist -= left[0]
    else:    
        dist -= max(right[-1], -left[0])
    
    print(dist)
    
    
q=nn()
for _ in range(q):
    solve()