import sys
import math
def II():
	return int(sys.stdin.readline())

def LI():
	return list(map(int, sys.stdin.readline().split()))

def MI():
	return map(int, sys.stdin.readline().split())

def SI():
	return sys.stdin.readline().strip()
t = II()
for q in range(t):
	n,k = MI()
	s = SI()
	l = []
	for i in range(n):
		if s[i] == "1":
			l.append(i)
	if len(l) == 0:
		print(max(1,1+(n-1)//(k+1)))
	else:
		count = l[0]//(k+1)
		for i in range(1,len(l)):
			count+=(l[i]-l[i-1]-1)//(k+1)
		count+=(n-l[-1]-1)//(k+1)
		print(count)

