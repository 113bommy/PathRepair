N, K = list(map(int, input().split()))
print(N + K) if N % K == 0 else print(N - K) 