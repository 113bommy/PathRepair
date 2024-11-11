import math
import sys
#from collections import deque, Counter, OrderedDict, defaultdict
#import heapq
#ceil,floor,log,sqrt,factorial,pow,pi,gcd
#import bisect
#from bisect import bisect_left,bisect_right
input = sys.stdin.readline
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input().strip()
    return(list(s[:len(s)]))
def invr():
    return(map(int,input().split()))
n,k=invr()
l=inlt()
mn=sum(l[:k])
temp=mn
idx=1
for i in range(k,n):
    temp+=(-l[i-k]+l[i])
    if temp<mn:
        idx=i-k+2
        mn=temp
print(idx)