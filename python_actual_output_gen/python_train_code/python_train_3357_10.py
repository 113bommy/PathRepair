n, k = map(int, input().split())

A = list(map(int, input().split()))

S = sum(A)
M = int(S / (float(n)))

i = 0

while M < k:
	i += 1
	M = (S + i*k) / (float(i + n))
	M = int(M + 0.5)

print(i)