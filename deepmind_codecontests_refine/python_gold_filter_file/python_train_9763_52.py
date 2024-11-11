A, B, C, K = map(int, input().split())
S = min(A, K) - max(0, K-A-B)
print(S)