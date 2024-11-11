import sys

input = sys.stdin.readline

def solve():
	a = input().strip()
	b = input().strip()

	n = len(a)
	m = len(b)
	c = [0]*m
	d = [0]*m

	p = 0
	for i in range(m):
		for j in range(p, n):
			if a[j] == b[i]:
				c[i] = j
				p = j + 1
				break
		else:
			for j in range(i,m):
				c[j] = n
			break
	p = n-1
	for i in range(m-1,-1,-1):
		for j in range(p,-1,-1):
			if a[j] == b[i]:
				d[i] = j
				p = j - 1
				break
		else:
			for j in range(i,-1,-1):
				d[j] = -1
			break
	j = 0
	while j < m and d[j] < 0:
		j += 1
	res = (m-j, 0, j)
	for i in range(m):
		p = c[i]
		if p == n:
			break
		while j < m and (j <= i or d[j] <= p):
			j += 1
		res = max(res,(i+1+m-j,i+1,j))
	if res[0] == 0:
		print('-')
	else:
		print(b[:res[1]]+b[res[2]:])

solve()
