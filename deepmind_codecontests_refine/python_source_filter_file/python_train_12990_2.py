A, B, N = map(int, input().split())

print(A * min(B-1, N) / B // 1)