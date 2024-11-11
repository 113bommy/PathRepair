import bisect

N = int(input())
L = []
L.append(int(input()))
c = 1

for i in range(N - 1):
	A = -int(input())
	x = bisect.bisect_right(L, A)
	if x == c:
		L.append(A)
		c += 1
	else:
		L[x] = A

print(c)