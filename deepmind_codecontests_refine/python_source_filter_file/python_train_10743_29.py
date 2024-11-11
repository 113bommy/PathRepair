import sys
import math
import decimal
from collections import OrderedDict
def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def minput():   return map(int, input().split()) 
def listinput(): return list(map(int, input().split()))
for _ in range(iinput()):
	n,m=minput()
	a=listinput()
	if n>m:print(-1)
	else:
		print(2*sum(a))
		for i in range(m-1):
			print(i+1,i+2)
		print(m,1)