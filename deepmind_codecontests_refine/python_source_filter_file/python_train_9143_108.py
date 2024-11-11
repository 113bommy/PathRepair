A, B, C, D = map(int, input().split())

print(max(min(A + B, C + D) - max(A, C), 0))