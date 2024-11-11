A, B, K = map(int, input().split())
print(max(0, A-K), min(B, B-K+A))