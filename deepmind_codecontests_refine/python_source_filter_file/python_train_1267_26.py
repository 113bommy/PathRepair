from heapq import heappush, heappop
from collections import deque
import itertools
from itertools import permutations
import sys
import bisect
sys.setrecursionlimit(10**6)
def MI():
    return map(int,input().split())
def I():
    return int(input())
def LI():
    return [int(i) for i in input().split()]
YN=['Yes','No']
YNeos='YNeos'
GYN=['Yes','trumpet']
mo=10**9+7
imp='IMPOSSIBLE'


n,x,y=LI()
q=deque()
a=LI()
b=[0]*n
for i in range(n):
    b[i]=min(a[max(0,i-x):min(i+y+1,n-1)])
for i in range(n):
    if b[i]==a[i]:
        print(i+1)
        break