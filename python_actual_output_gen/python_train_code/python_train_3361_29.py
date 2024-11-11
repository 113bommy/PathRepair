A, B, C, K = map(int, input().split())
ans = A
print(ans - max(K - A - B, 0))