A, B, C, K = map(int, input().split())
ans = min(A, K) - min(0, K - A - B)
print(ans)