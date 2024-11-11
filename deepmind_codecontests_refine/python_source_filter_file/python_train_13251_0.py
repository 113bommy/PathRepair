A = [int(_) for _ in input().split()]

if abs(A[3]-A[2]) > 1: print(-1)

elif A[2] > A[3]:
	if A[0] < A[2] or A[1] < A[2]: print(-1)
	else:	
		A[0] -= A[2]
		A[1] -= A[2]
		print("4"*A[0]+"47"*A[2]+"7"*A[1])

elif A[3] > A[2]:
	if A[1] < A[3] or A[2] < A[3]: print(-1)
	else:
		A[0] -= A[3]-1
		A[1] -= A[3]-1
		print("7"+"4"*A[0]+"74"*(A[3]-2)+"7"*A[1]+"4")

else:

	if A[2]+1 <= A[0] and A[3] <= A[1]:
		A[0] -= A[2]+1
		A[1] -= A[3]

		print("4"*A[0]+"47"*A[2]+"7"*A[1]+"4")

	elif A[2] <= A[0] and A[3]+1 <= A[1]:
		A[1] -= A[3]

		print("74"*A[3]+"7"*A[1])

	else:
		print(-1)
