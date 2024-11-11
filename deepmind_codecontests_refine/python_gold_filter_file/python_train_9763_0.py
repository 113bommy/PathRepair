a, b, c, k = [int(i) for i in input().split()]

print(min(a, k) - max(0, k-a-b))