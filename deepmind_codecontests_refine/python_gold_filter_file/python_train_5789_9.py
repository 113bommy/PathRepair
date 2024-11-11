import math as mt 
import sys,string,bisect
input=sys.stdin.readline
import random
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
l1=L()
l2=L()
l3=L()
l4=L()
if((sum(l1)>=2 and l1[-1]) or (sum(l2)>=2 and l2[-1]) or (sum(l3)>=2 and l3[-1]) or (sum(l4)>=2 and l4[-1])):
    print("YES")
    exit()
if(l1[-1]==1):
    if(l4[2] or l2[0] or l3[1]):
        print("YES")
        exit()
if(l2[-1]==1):
    if(l4[1] or l3[0] or l1[2]):
        print("YES")
        exit()
if(l3[-1]==1):
    if(l4[0] or l1[1] or l2[2]):
        print("YES")
        exit()
if(l4[-1]==1):
    if(l3[2] or l2[1] or l1[0]):
        print("YES")
        exit()
print("NO")
    
