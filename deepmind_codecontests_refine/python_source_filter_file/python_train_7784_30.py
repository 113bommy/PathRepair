N, M = map(int, input().split())

if N % 2 == 1:
    for a in range(1, M + 1):
        print(a, N - a + 1)
else:
    for a in range(1, M + 1):
        if a <= M // 2:
            print(a, N - a + 1)
        else:
            print(a, N - a)