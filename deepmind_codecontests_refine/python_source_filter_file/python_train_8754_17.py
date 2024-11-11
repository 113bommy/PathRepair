import sys

input = sys.stdin.readline

from random import randint

def solve():
	n, k = map(int, input().split())
	l = 1
	r = n
	while True:
		c = (l+r)//2
		w1 = min(c+k,n)-max(l-k,1)
		w2 = min(r+k,n)-max(c+1-k,1)
		if max(w1, w2) >= r-l+1:
			pos = randint(l, r)
			print(pos, pos)
			sys.stdout.flush()
			if input().strip() == 'Yes':
				break
		else:
			print(l, c)
			sys.stdout.flush()
			if input().strip() == 'Yes':
				if l == c:
					break
				r = c
			else:
				l = c+1
		l = max(l-k, 1)
		r = min(r+k, n)

solve()
