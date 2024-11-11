n, a, b = map(int, input().split())

print(min(a, b), min(0, n - a - b))