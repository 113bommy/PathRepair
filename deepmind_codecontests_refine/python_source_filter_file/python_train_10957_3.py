import sys
input = lambda: sys.stdin.readline().rstrip()
# import sys
# import math
# input = sys.stdin.readline
from collections import deque
from queue import LifoQueue
for _ in range(int(input())):
	n = int(input())
	a = input()
	b = input()
	a1 = []
	a2 = []
	# if n==1:
	# 	if a[0]==b[0]:
	# 		print(0)
	# 	else:
	# 		print(1,1)

	for i in range(0,n,2):
		if a[i:i+2]=='01':
			a1.append(i+1)
			a1.append(i+2)
		elif a[i:i+2]=='10':
			if i!=0:
				a1.append(i)
			a1.append(i+1)
		elif a[i:i+2]=='11':
			if i!=0:
				a1.append(i)
			a1.append(i+2)
		elif a[i:i+2]=='1':
			if n-1>0:
				a1.append(n-1)
			a1.append(n)
	for i in range(0,n,2):
		if b[i:i+2]=='01':
			a2.append(i+1)
			a2.append(i+2)
		elif b[i:i+2]=='10':
			if i!=0:
				a2.append(i)
			a2.append(i+1)
		elif b[i:i+2]=='11':
			if i!=0:
				a2.append(i)
			a2.append(i+2)
		elif b[i:i+2]=='1':
			if n-1>0:
				a2.append(n-1)
			a2.append(n)
	a2.reverse()
	c = a1+a2
	print(*c)
	for i in range(len(c)-1):
		if c[i]==c[i+1]:
			c.pop(i)
			c.pop(i)
			break
	print(len(c),*c)