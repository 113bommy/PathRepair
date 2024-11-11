N, M = map(int, input().split())
A = [int(a) for a in input().split()]
A.sort(reverse=True)
print("Yes" if A[M - 1] >= sum(A) / (4 * M) else "No")