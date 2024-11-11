from collections import Counter,defaultdict,deque
import heapq as hq
#from itertools import count, islice
#from functools import reduce
#alph = 'abcdefghijklmnopqrstuvwxyz'
#from math import factorial as fact
#a,b = [int(x) for x in input().split()]
import math
import sys
input=sys.stdin.readline
def getx(target,cursum,curk):
    left = 0
    right = curk
    while left<=right:
        mid = (left+right)//2
        if cursum+mid+mid+mid>target:
            right = mid-1
        else:
            left = mid+1
    return right
    
def solve():
    n = int(input())
    cur = [1,1]
    res = []
    s = 2
    t = 0
    while cur[0]<n:
        s = sum(cur)
        x = min(cur[1],getx(n,s,cur[1]))
        if s+cur[1]>=n:
            x = n-s
        #print(cur[1])
        cur[1]+=x
        cur[0]+=cur[1]
        res.append(x)
        #print(cur)
    print(len(res))
    print(*res)
        
   

tt = int(input())
for test in range(tt):
    solve()















#
