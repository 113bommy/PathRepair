cases = int(input().strip())

for case in range(cases):
	n, d = list(map(int, input().strip().split(" ")))
	a = list(map(int, input().strip().split(" ")))
	done = False
	for i in range(1, n):
		while a[i] > 0:
			if d > i:
				d -= i
				a[0] += 1
				a[i] -= 1
			else:
				done = True
				break
		if done:
			break
	print(a[0])
