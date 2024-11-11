
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

if n == 1:
	print(a[0] + b[0])
	exit()
max_val = 0
for i in range(n):
	for j in range(i, n):
		l1 = a[i:j]
		l2 = b[i:j]

		c = 0
		d = 0
		for ii in  l1:
			c |= ii

		for ii in l2:
			d |= ii

		if c + d > max_val:
			max_val = c + d

	






print(max_val)
