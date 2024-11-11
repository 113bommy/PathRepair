N, M = map(int, input().split())

if N >= (M // 2):
    print(M // 2)
else:
    print(N + ((M - 2 * N) // 4))