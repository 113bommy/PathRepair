from itertools import accumulate

N, K = map(int, input().split())
A = list(map(int, input().split()))

for _ in range(K):
    if A == [N] * N:
        break
    B = [0] * (N+1)
    for i, a in enumerate(A):
        start = max(0, i - a)
        end = min(N-1, i + a) + 1
        B[start] += 1
        B[end] -= 1
        A = list(accumulate(B))[:-1]
print(' '.join(map(str, A)))

