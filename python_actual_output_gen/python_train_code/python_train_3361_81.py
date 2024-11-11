A, B, C, K = map(int, input().split())
ans = min(A, K) - min(C, K - A - B)
print(ans)