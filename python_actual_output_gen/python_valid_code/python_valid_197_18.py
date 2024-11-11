a, b, c = map(int, input().split())

print(c*2 + min(a, b) * 2 + (max(a, b) - min(a, b)) > 0)