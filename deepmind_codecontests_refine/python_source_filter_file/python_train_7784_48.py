N, M = map(int, input().split())

for i in range(min(N, M // 4)):
    print("{} {}".format(i + 1, M - i))

center = (M + 1) // 2

for i in range(max(0, N - M // 4)):
    print("{} {}".format(center - i - 1, center + i + 1))