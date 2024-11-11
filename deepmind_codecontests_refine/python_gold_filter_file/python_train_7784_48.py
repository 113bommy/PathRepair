N, M = map(int, input().split())

for i in range(min(M, N // 4)):
    print("{} {}".format(i + 1, N - i))

center = (N + 1) // 2

for i in range(max(0, M - N // 4)):
    print("{} {}".format(center - i - 1, center + i + 1))