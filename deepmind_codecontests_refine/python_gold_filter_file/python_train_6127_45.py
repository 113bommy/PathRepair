N, M = map(int, input().split())

if M >= 2 * N:
    print(N + (M - 2 * N) // 4)
else:
    print(M // 2)