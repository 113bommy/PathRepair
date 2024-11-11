n, k = map(int, input().split())
if k == 1:
	print(0)
else:
	if k < n:
		if k%2:
			print(k//2)
		else:
			print(k//2 - 1)
	else:
		t = k-n
		if t > n-1:
			print(0)
		else:
			p = n-t+1
			print(p//2)