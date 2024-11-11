N, K = map(int, input().split())

print(min(N % K, N - N % K))
