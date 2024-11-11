K, N, *A = map(int, open(0).read().split())

A.append(K + A[0])

B = [b - a for a, b in zip(A, A[1:])]
print(sum(B) - max(B))