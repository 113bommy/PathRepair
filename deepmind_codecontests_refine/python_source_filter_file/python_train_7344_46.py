import math as mt
import sys
from collections import *

inf = float('inf')
def ii(): return int(input())
def mii(): return map(int, input().split())
def lii(): return list(map(int, input().split()))
def gmat(n,m): return [[0]*m for _ in range(n)]
def imat(n): return [list(mii()) for _ in range(n)]

try:
	sys.stdin = open('a.in', 'r') 
	input = sys.stdin.readline
except:pass


a,b,c=mii()
aps = lii()
f,s = 0,0
for i in aps:
	if i<b: 
		s+=i
	else: continue
	if s>c:
		s=0
		f+=1
print(f)