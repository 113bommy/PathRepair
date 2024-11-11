import sys
def input():
	return sys.stdin.buffer.readline()[:-1]

for T in range(1):
	n, m = map(int, input().split())
	p = list(map(int, input().split()))
	q = list(map(int, input().split()))

	ok, ng = 10**11, 0
	while ok-ng > 1:
		x = (ok+ng)//2
		flg = True
		j = 0
		for i in range(n):
			l = max(p[i] - q[j], 0)
			if l > x:
				flg = False
				break
			while j < m and q[j] < p[i]:
				j += 1
			if j == m:
				break
			while j < m:
				r = q[j] - p[i]
				if min(l, r)*2 + max(l, r) <= x:
					j += 1
					continue
				else:
					break
			if j == m:
				break
		if flg == False or j < m:
			ng = x
		else:
			ok = x
	print(ok)