A, B, C, K = list(map(int, input().split()))
if K % 2 == 0:
	print(A - B)
else:
	print(A - B) * (-1)