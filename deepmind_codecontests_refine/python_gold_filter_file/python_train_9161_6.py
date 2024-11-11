import sys

a_max = 10000000000

def merge_sort(A):
	n = len(A)
	num_swap = 0

	if n > 1:
		m = n // 2
		num_swap0, A0 = merge_sort(A[0:m])
		num_swap1, A1 = merge_sort(A[m:])
		
		num_swap += num_swap0 + num_swap1

		n1 = len(A0)
		A0.append(a_max)
		A1.append(a_max)	
		i = 0
		j = 0		
		
		for k in range(n):
			if A0[i] < A1[j]:
				A[k] = A0[i]

				i += 1
			else:
				A[k] = A1[j]

				num_swap += n1 - i
				j += 1

	return num_swap, A

def bubble_sort(A):
	n = len(A)
	num_swap = 0

	for i in range(n):
		for j in range(n - 1, i, -1):
			if A[j] < A[j - 1]:
				A[j], A[j - 1] = A[j - 1], A[j]
				num_swap += 1

	return num_swap, A

#fin = open("test.txt", "r")
fin = sys.stdin

fin.readline()
A = list(map(int, fin.readline().split()))

num_swap, B = merge_sort(A)
#num_swap, B = bubble_sort(A)

print(num_swap)
#print(B)