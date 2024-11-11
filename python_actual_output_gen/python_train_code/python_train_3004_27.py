M, N = map(int, input().split())
A = list(map(int, input().split()))
A.sort(reverse=True)
print("Yes" if A[N-1] * 4 * M > sum(A) else "No")