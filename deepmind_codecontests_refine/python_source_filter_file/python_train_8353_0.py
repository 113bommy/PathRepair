import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def find(cnt, k, h):
	l = 0
	r = 2001
	while r-l > 1:
		now = 0
		c = (l + r) // 2
		for j in cnt:
			now += j//c
		if now >= h:
			l = c
		else:
			r = c
	return l*h

def solve():
	n, k = mints()
	cnt = [0] * 26
	for i in minp():
		cnt[ord(i) - ord('a')] += 1
	cnt.sort(reverse = True)
	ans = 0
	for i in range(1,k):
		if k % i == 0:
			ans = max(ans, find(cnt, k, i))
			if k // i != i:
				ans = max(ans, find(cnt, k, k // i))
	print(ans)

for i in range(mint()):
	solve()
