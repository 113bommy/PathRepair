# AOJ 0517: Longest Steps
# Python3 2018.6.30 bal4u

while True:
	n, k = map(int, input().split())
	if n == 0: break
	c = [0]*(n+1)
	f = 0;
	for i in range(k):
		a = int(input())
		if a == 0: f = 1
		else: c[a] = 1
	ans = w0 = w = 0
	for i in range(1, n+1):
		if c[i]: w += 1
		elif w > 0:
			if w0 + w + f > ans: ans = w0 + w + f
			w0 = w if f and c[i+1] else 0
			w = 0
	if w0 + w + f > ans: ans = w0 + w + f
	print(ans)
