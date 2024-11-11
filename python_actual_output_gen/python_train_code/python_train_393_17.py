k = int(input().strip())
n = list(map(int, input().strip()))
sumN = sum(n)
if sumN >= k:
	print(0)
else:
	n.sort()
	i = 0
	c = 0
	while sumN < k:
		sumN += 9-n[i]
		c += 1
	print(c)