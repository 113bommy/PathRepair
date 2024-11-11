import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

n, m, a, b = mints()
A = list(mints())
B = list(mints())
l = list(mints())
j = -1
r = (1e100,-1,-1)
for i in range(m):
	while not((j == -1 or a*B[i]-b*A[j] >= 0) \
		and (j+1 == n or a*B[i]-b*A[j+1] < 0)):
		j += 1
	#print(j)#,a*B[i]-b*A[j],a*B[i]-b*A[j+1])
	if j != -1:
		r = min(r,(l[i]+sqrt(a*a+A[j]*A[j])+sqrt((b-a)**2+(B[i]-A[j])**2),j,i))
	if j+1 != n:
		r = min(r,(l[i]+sqrt(a*a+A[j+1]*A[j+1])+sqrt((b-a)**2+(B[i]-A[j+1])**2),j+1,i))
print(r[1]+1,r[2]+1)