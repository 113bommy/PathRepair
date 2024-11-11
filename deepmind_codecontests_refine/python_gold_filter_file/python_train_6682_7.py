from math import *
#from bisect import *
#from collections import *
#from random import *
#from decimal import *"""
#from heapq import *
#from random import *
import sys
input=sys.stdin.readline
#sys.setrecursionlimit(3*(10**5))
global flag
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
t=1
global li
li=[]
def rec(st,tu):
    global li
    if(tu>10):
        return
    if(st):
        li.append(int(st))
    rec(st+'4',tu+1)
    rec(st+'7',tu+1)
rec('',0)
while(t):
    t-=1
    l,r=ma()
    li.sort()
    co=0
    for i in li:
        if(int(i)<l):
            continue
        need=min(int(i)-l+1,r-l+1)
        #print(need,l,i)
        l+=need
        co+=need*int(i)
        if(l>r):
            break
    print(co)
