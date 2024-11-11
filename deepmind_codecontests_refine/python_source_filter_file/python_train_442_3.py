import sys 
from collections import defaultdict as dd
from collections import Counter as cc
from queue import Queue
import math
import itertools
try:
    sys.stdin = open('input.txt', 'r') 
    sys.stdout = open('output.txt', 'w')
except:
    pass
input = lambda: sys.stdin.buffer.readline().rstrip()


w=int(input())
q=list(map(int,input().split()))
a=[]
d=0
e=0
f=0
b=[]
c=0
j=w
k=0
u=0
for i in range(w-1,-1,-1):
	if q[i]==1:
		a.append(i+1)
		d+=1
		u=0
	elif q[i]==2:
		if d>(e+f):
			b.append([j,i+1])
			b.append([j,a[k]])
			j-=1
			k+=1
			e+=1
			u=1
		else:
			c=1
			break
	elif q[i]==3:
		if u==1:
			b.append([j,i+1])
			b.append([j,b[-3][1]])
			j-=1
		elif u==2:
			b.append([j,i+1])
			b.append([j,b[-3][1]])
			j-=1
		elif d>(e+f):
			b.append([j,a[k]])
			j-=1
			b.append([j,i+1])
			b.append([j,a[k]])
			j-=1
			k+=1
			f+=1
		else:
			c=1
			break
		u=2
while k<len(a):
	b.append([j,a[k]])
	j+=1
	k+=1
if c==1:
	print(-1)
else:
	print(len(b))
	for i in b:
		print(*i)