A, B, C, D = [int(i) for i in input().split()]
print(max(0, min(B, D) - max(A, C)))