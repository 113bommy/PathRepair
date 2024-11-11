import sys
import os.path
import math
import heapq
from sys import stdin,stdout
from collections import*
from math import gcd,ceil,floor
mod = int(1e9+7)
##input=sys.stdin.readline
if os.path.exists('Updated prg/Input3d.txt'):
    sys.stdout=open("Updated prg/Output3d.txt","w")
    sys.stdin=open("Updated prg/Input3d.txt","r")
def sinp():return input()
def ninp():return int(sinp())
def mapinp():return map(int,sinp().split())
def linp():return list(mapinp())
def sl():return list(sinp())
def prnt(a):print(a)
l1=[]
for _ in range(ninp()):
    a,b=mapinp()
    l1.append([a,b])
##c=l1[0][1]
c=0
m1=0
for i in range(0,len(l1)):
    c=c-l1[i][0]
    c=c+l1[i][1]
    if c>m1:
        m1=c
prnt(m1)