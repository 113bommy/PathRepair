import sys

def minp():
	return sys.stdin.readline().strip()

n,mm,k = map(int,minp().split())
a = list(map(int,minp().split()))
def tt(x):
	m = mm
	c = 0
	for j in range(x,n):
		i = a[j]
		if c + i >= k:
			if m == 0 or i > k:
				return False
			c = i
			m -= 1
			if i == k:
				if m == 0:
					return False
				m -= 1
				c = 0
		else:
			c += i
	return True
l = 0
r = n
while l < r:
	c = (l+r)//2
	if tt(c):
		r = c
	else:
		l = c+1
print(n-r)