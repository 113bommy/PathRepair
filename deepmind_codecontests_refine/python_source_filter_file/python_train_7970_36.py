from math import sqrt, floor

n, k = map(int, input().split())

print(min(n, floor(0.5 * (-1 + sqrt(96 - 0.4 * k)))))
