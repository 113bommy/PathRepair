N, x = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]
eat = [0] * N
eat[0] = A[0] - x
for i in range(N - 1):
    eat[i + 1] = max(A[i + 1] + A[i] - eat[i] - x, 0)
print(sum(eat))
