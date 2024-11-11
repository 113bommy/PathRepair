A, B, C, K = map(int, input().split())
ans = min(A, K)
print(ans - max(K - A - B, 0))
