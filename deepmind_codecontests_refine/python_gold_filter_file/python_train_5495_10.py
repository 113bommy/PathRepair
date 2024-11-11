K, N = map(int, input().split())
A = list(map(int, input().split()))

A.append(A[0]+K)
print(K-max(abs(b-a) for a, b in zip(A, A[1:])))
