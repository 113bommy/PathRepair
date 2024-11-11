A, B, C, K = map(int, input().split())

ans = min(A, K) - max(K - A - B, 0)
print(ans)