A, B, C, D = map(int, input().split())
print(min(min(B, D) - max(A, C), 0))