N, M = map(int, input().split())
if N > M:
    N, M = M, N
if N == 1 and M == 1:
    print(0)
elif N == 1:
    print(M - 2)
else:
    print(N * M - 2 * N - 2 * M + 4)
