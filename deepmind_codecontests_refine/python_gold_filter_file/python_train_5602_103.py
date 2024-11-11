a, b = map(int, input().split())
print(max(max(a, b) * 2 - 1, a + b))