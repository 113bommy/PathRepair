A, B, C, D = list(map(int, input().split()))

print(max(0, min(B, D) - max(A, C)))