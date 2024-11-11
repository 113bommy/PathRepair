N = int(input())

S = []

for _ in range(N):
	A = int(input())
	if A in S:
		S.remove(A)
	else:
		S.append(A)

print(len(S))