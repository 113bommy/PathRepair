# -*- coding: utf-8 -*-

def work(x):
	if (x>a):
		if (x%2==0):
			t = work(x//2)
			if (t < 0): return -1
			f[x] = x//2
			return t+1
		elif (x%10==1):
			t = work(x//10)
			if (t < 0): return -1
			f[x] = x//10
			return t+1
		else: return -1
	elif (x==a): return 0
	else: return -1

def printf(x):
	if (x!=a):
		printf(f[x])
	if (x!=b): print(x,end=' ')
	else: print(x,end='\n')
	return
	
a, b = input().split(' ')
a = int(a)
b = int(b)
f = {}
ans = work(b)
if ans < 0 : print('NO')
else:
	print('YES')
	print(ans)
	printf(b)