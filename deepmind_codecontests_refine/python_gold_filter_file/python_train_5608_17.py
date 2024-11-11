A, B, C = sorted([int(x) for x in input().strip().split()])
print(A * B * (C % 2))