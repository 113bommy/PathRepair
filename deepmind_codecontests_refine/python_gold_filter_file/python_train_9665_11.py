N = int(input())

S = set()

for _ in range(N):
	A = int(input())
	if A in S:
		S.remove(A)
	else:
		S.add(A)

print(len(S))