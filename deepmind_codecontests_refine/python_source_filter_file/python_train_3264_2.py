n, m = map(int,input().split())
l = list(map(int,input().split()))


def g(f):
	A = l[:]; s = 0
	for _ in range(n):
		i = A.index(f(A)); s += A[i]

		if A[i] >= 1: A[i] -= 1;
		else:
			A.pop(i)
	return s
print (g(max), g(min))