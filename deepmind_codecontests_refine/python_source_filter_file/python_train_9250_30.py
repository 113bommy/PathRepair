N, K, X, Y = [int(input() for _ in range(4))]
print(min(N, K) * X + max(0, N - K) * Y)