A, B, C, D = map(int, input().split())
print(max(min(C, D)-max(A, B), 0))