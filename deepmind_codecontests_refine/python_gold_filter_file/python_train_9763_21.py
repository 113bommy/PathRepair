A, B, C, K = map(int, input().split())
print(min(A, K) - max(0, (K - A - B)))