from math import ceil

a, b, c = map(int, input().split())
print(ceil(c * ((a / b) - 1)))
