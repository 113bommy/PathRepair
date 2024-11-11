
import heapq,math
from collections import defaultdict,deque
from os import getcwd

import sys, os.path
#sys.setrecursionlimit(10000000)

if(os.path.exists('C:/Users/Dhanush/Desktop/cp/input.txt')):
    sys.stdout = open('C:/Users/Dhanush/Desktop/cp/output.txt', 'w')
    sys.stdin = open('C:/Users/Dhanush/Desktop/cp/input.txt', 'r')

input=sys.stdin.readline

k=int(input())
for _ in range(k):
    n,x,t=map(int,input().split())
    if(t<x):
        print(0)
    elif(t==x):
        print(n-1)
    else:
        count=t//x
        ans=max(0,n-count)*count
        temp=count-1
        ans+=(temp*(temp+1))//2
        print(ans)
