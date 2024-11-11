a, b, c, d = list(map(int, input().split()))
print(max(0, min(b, d) - max(a, c)))
