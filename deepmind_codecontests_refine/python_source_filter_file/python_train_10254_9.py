import sys
import copy
from math import *
from collections import deque
sys.setrecursionlimit(10**7)
def eprint(*args):
    print(*args, file=sys.stderr)
zz=1

if zz:
	input=sys.stdin.readline
else:	
	sys.stdin=open('input.txt', 'r')
	sys.stdout=open('output2.txt','w')
a=list(input().rstrip())
b=list(input().rstrip())
c=0
def rec(a):
	global c
	if len(a)==1:
		return a
	#print(a,b,c)
	s1=rec(a[len(a)//2:])
	s2=rec(a[:len(a)//2])
	return min(s1,s2)+max(s1,s2)
	
	

print("YES" if rec(a)==rec(b) else "NO")	