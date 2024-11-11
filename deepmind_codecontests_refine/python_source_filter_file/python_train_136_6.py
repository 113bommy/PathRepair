from math import ceil

a, b, c = map(int, input().split())
print(ceil(round(c * ((a / b) - 1), 2)))
