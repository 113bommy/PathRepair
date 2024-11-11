import sys
n,m = input().split()
n = int(n)
m = int(m)
l = [0]*(n+1)
r = 0
if(n == 1):
	print(0)
	sys.exit()
for i in range(m):
	e1,e2 = input().split()
	e1 = int(e1)
	e2 = int(e2)
	l[e1] = 1
	l[e2] = 1
for i in range(1,n):
	if(l[i] == 0):
		r = i
		break
print(n-1)
for i in range(n):
	if(i+1 != r):
		print(r,i+1)