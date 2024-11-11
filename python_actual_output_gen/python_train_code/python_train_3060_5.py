a, b = map(int, input().split())
print((b * (b - 1) * a * (a * b + b + 2) / 4)  % 1000000007)