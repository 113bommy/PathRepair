import sys
import math
 
def read_line():
	return sys.stdin.readline()[:-1]
 
def read_int():
	return int(sys.stdin.readline())
 
def read_int_line():
	return [int(v) for v in sys.stdin.readline().split()]

t = read_int()

for i in range(t):
	n,x = read_int_line()
	s = read_line()

	l = [0 for i in range(n)]

	if s[0]=="0":
		l[0] = 1
	else:
		l[0] = -1

	cnt = 0

	for i in range(1,n):
		if l[i]==x:
			cnt+=1
		if s[i]=="1":
			l[i]=l[i-1]-1
		else:
			l[i]=l[i-1]+1

	f = False
	for i in range(n):
		if x-l[i]==0 and l[n-1]==0:
			f = True

	if not f and l[n-1]!=0:
		for j in range(n):
			if (x-l[j])%l[n-1] == 0:
				if ((x-l[j])//l[n-1])*n + j+1 >= 0:
					cnt+=1
		
		print(cnt)

	if not f and l[n-1]==0:
		print(0)

	else:
		print(-1)