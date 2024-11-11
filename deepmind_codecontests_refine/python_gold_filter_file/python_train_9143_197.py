A, B, C, D = map(int, input().split())
print(max(min(D, B) - max(A, C), 0))