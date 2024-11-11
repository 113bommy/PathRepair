n, q, k = map(int, input().split())
a = list(map(int, input().split()))
b, c = [], [0]
if n > 1:
	for i in range(n):
		if i == 0:
			b.append(a[i+1] - 3)
		elif i == (n-1):
			b.append(k - a[i-1] - 2)
		else: 
			b.append(a[i+1] - a[i-1] - 2)
	for i in range(n):
		c.append(c[i] + b[i])

for i in range(q):
	if n == 1:
		print(k-3)
		continue
	result = 0
	l, r = map(int, input().split())
	if l == r:
		print(k-3)
		continue
	l -= 1
	r -= 1
	result += a[l+1] + k - a[r-1] - 3
	result += c[r] - c[l+1]
	print(result)