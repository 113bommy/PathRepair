A, B, K = input().split()

A = int(A)
B = int(B)
K = int(K)

for i in range(K):
	if i % 2 == 0:
		A //= 2
		B += A 
	else:
		B //= 2
		A += B 
print(str(A) + " " + str(B))
