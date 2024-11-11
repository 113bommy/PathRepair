A, B, C, K = map(int, input().split())
print(min(K, A) - max(K - A - B, 0))
