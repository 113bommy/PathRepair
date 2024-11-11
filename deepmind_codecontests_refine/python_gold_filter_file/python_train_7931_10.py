q = int(input())
for c in range(q) :
	n = int(input())
	A = list(map(int, input().split()))
	A.sort()
	B = [[A[0]]]
	for i in range(0, n) :
		for j in range(0, len(B)) :
			if B[j][len(B[j]) - 1] != (A[i] - 1) and B[j][len(B[j]) - 1] != (A[i] + 1) :
				B[j].append(A[i])
				break
			elif j == len(B) - 1 :
				B.append([A[i]])
	print(len(B))
