# from debug import debug
import sys
input = sys.stdin.readline
inf = int(1e10)

t = int(input())
while t:
	t-=1
	n = int(input())
	s = input().strip()
	x, y = 0, 0
	l1 = -1
	d = {(x,y): 0}
	small = inf
	l, h = -1, 0
	for i in range(n):
		if s[i] == 'L':
			x-=1
		elif s[i] == 'R':
			x+=1
		elif s[i] == 'U':
			y-=1
		else:
			y+=1
		if (x,y) in d:
			if i+1-d[(x,y)] < small:
				small = i+1-d[(x,y)]
				l = i-small+2
				h = i+1
		d[(x,y)] = i+1
	if small == inf:
		print(-1)
	else:
		print(l, h)
		