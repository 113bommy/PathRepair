def getint():
    return [int(i) for i in input().split()]
def get():
    return int(input())
def getstr():
    return [i for i in input().split()]
def S():
    for test in range(int(input())):
        solve()
import math
import itertools as it
import bisect
import time
import collections as ct

def solve():
    n=get()
    a=getint()
    a=[0]+a
    flag=False
    if n%2==0:
        flag=True
    for i in range(2,n+1):
        if a[i]<a[i-1]:
            flag=True
    if flag:
        print("YES")
    else:
        print("NO")




S()