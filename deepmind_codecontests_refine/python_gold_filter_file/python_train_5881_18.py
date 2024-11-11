N = int(input())
A = list(map(int, list(input())))
B = list(map(int, list(input())))
C = 0
for a, b in list(zip(A, B)):
	D = abs(a - b)
	C += min(D, (10 - D) % 10)
print(C)