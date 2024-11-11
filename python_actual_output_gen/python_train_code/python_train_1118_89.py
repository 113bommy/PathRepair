A, B, K = map(int, input().split())

print(max(A-K, 0), B - max(0, (K - A)))
