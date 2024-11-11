n = int(input())
for i in range(1, 1000):
	if i*i >= n:
		if i*(i-1) >= n:
			print(2*i + 2*(i-1))
		else:
			print(4*i)
		break