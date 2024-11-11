A = sorted(list(map(int, input().split())))
if all(a % 2 == 0 for a in A):
	print(0)
else:
	print(A[0] * A[1])