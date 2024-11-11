A = input()
while(A != '-'):
	m = int(input)
	for i in range(m):
		h = int(input())
		A = A[h:]+A[:h]
	print(A)
	A = input()
