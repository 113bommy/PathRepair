A, B, C, D = map(int, input().split())
print(min(0, min(C, D) - max(A, B)))