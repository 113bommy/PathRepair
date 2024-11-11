import sys
#from collections import deque
#from functools import *
#from fractions import Fraction as f
from copy import *
from bisect import *	
#from heapq import *
#from math import gcd
#from itertools import permutations ,product
 
def eprint(*args):
    print(*args, file=sys.stderr)
zz=1
 
#sys.setrecursionlimit(10**6)
if zz:
	input=sys.stdin.readline
else:	
	sys.stdin=open('input.txt', 'r')
	sys.stdout=open('all.txt','w')
di=[[-1,0],[1,0],[0,1],[0,-1]]
def inc(d,c,x=1):
	d[c]=d[c]+x if c in d else x
def bo(i):
	return ord(i)-ord('A')	
def li():
	return [int(xx) for xx in input().split()]
def fli():
	return [float(x) for x in input().split()]	
def comp(a,b):
	if(a>b):
		return 2
	return 2 if a==b else 0		
def gi():	
	return [xx for xx in input().split()]
def fi():
	return int(input())
def pro(a): 
	return reduce(lambda a,b:a*b,a)		
def swap(a,i,j): 
	a[i],a[j]=a[j],a[i]	
def si():
	return list(input().rstrip())	
def mi():
	return 	map(int,input().split())			
def gh():
	sys.stdout.flush()
def isvalid(i,j):
	return 0<=i<n and 0<=j<m and a[i][j]!="."
def bo(i):
	return ord(i)-ord('a')	
def graph(n,m):
	for i in range(m):
		x,y=mi()
		a[x].append(y)
		a[y].append(x)

t=1


while t>0:
	t-=1
	n=fi()
	a=li()
	a.sort(reverse=True)
	ans=[0]*n
	a=a[:(n+1)//2]+sorted(a[(n+1)//2:])
	l=c=0
	r=n-1
	#print(a)
	for i in range(n):
		if i%2:
			ans[i]=a[r]
			r-=1
		else:
			ans[i]=a[l]
			l+=1	

			
	for i in range(1,n-1):
		if ans[i]<ans[i-1] and ans[i]<ans[i+1]:
			c+=1
	print(c)		
	print(*ans)		
