N, M = map(int, input().split())

if N <= M:
    print(N + (M - 2 * N) // 4)
else:
    print(M // 2)