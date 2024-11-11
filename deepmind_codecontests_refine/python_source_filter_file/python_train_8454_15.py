
for _ in range(int(input())):
	n = int(input())
	arr = [int(i) for i in input().strip().split()]
	s = sum(arr)
	zero = 0
	ans = 0
	for i in arr:
		if i == 0:
			zero+=1

	if zero == 0:
		if s == 0:
			ans = 1
		else:
			ans = 0
	else:
		if s > 0:
			ans = zero
		elif s == 0:
			ans = zero
		else:
			if s == -1*zero:
				ans = zero+1
			else:
				ans = 0
	print(ans)
