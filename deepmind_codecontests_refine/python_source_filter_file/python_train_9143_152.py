A, B, C, D = map(int, input().split())
print(min(0, min(B, D) - max(A, C)))