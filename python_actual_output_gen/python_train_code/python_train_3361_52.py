A, B, C, K = map(int, input().split())
print(max(A - K, A) - max(0, (K - A - B)))