n, k = map(int, input().split())
print(max(0, k // 2 - max(0, k - 1 - n)))