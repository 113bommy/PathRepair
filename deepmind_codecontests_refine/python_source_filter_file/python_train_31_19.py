from math import ceil

n, x, y = map(int, input().split())

tot = ceil(n * y / 100)
print(tot - x)
