A, B, C, K = map(int, input().split())
ans = max(0, min(K, A)) - max(0, K-A-B)
print(ans)