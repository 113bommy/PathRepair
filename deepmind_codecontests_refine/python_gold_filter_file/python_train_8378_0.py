import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

h, q = mints()
a = [None]*(q*2+1)
L = 1<<(h-1)
R = (1<<h)-1
j = 0
for i in range(q):
	hh,l,r,ans = mints()
	l = (l<<(h-hh))
	r = ((r+1)<<(h-hh))-1
	if ans == 1:
		L = max(L, l)
		R = min(R, r)
	else:
		a[j] = (l,-1)
		a[j+1] = (r+1,1)
		j+=2
if L > R:
	print("Game cheated!")
	exit(0)
a[j]=((1<<h),-1)
a = a[:j+1]
a.sort()
#print(a)
#print(L,R)
cnt = 0
t = 1<<(h-1)
ans = None
for i in a:
	if i[0] != t:
		kk = min(R+1,i[0])-max(t,L)
		#print(i,t,cnt,kk)
		if cnt == 0 and kk >= 1:
			if ans != None or kk > 1:
				print("Data not sufficient!")
				exit(0)
			ans = max(t,L)
		#print(ans)
		t = i[0]
	cnt -= i[1]
if ans == None:
	print("Game cheated!")
else:
	print(ans)