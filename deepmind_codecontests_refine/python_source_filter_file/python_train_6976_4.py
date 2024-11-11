import sys

def bubble_sort(C, N):
	for i in range(N):
		for j in range(N - 1, i, -1):
			if C[j][1] < C[j - 1][1]:
				C[j], C[j - 1] = C[j - 1], C[j]
				
	return C

def	selection_sort(C, N):
	for i in range(N):
		minj = i
		for j in range(i, N):
			if C[j][1] < C[minj][1]:
				minj = j

		C[i], C[minj] = C[minj], C[i]
	
	return C

fin = open("test.txt", "r")
#fin = sys.stdin

N = int(fin.readline())
A = fin.readline().split()
B = A[:]

A = bubble_sort(A, N)
B = selection_sort(B, N)

print(" ".join(A))
print("Stable")

print(" ".join(B))
if A == B:
	print("Stable")
else:
	print("Not stable")