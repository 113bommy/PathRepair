A, B, C, K = map(int, input().split())
out = min(A, K) - max(K-A-B, 0)