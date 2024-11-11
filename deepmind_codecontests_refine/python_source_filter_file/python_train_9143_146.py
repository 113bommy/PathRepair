A, B, C, D = map(int, input().split())
print(max(0, min(C, D) - max(A, B)))