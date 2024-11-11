a, b, c, k = map(int, input().split())

print(min(a, k) - max(0, (k - a - b)))