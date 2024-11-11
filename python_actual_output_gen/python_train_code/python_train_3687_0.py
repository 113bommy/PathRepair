# Bismillah
# In the name of GOD

t = int(input())
while t > 0:
	t -= 1
	d = input().split()
	n = int(d[0])
	a = int(d[1])
	b = int(d[2])
	c = int(d[3])
	d = int(d[4])
	if c - d < n * (a + b) or c + d < n * (a - b):
		print('No')
		continue
	print('Yes')

