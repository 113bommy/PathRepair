from math import ceil

s = int(input())
a = ceil(s / 10**9)
b = 10**9*a - s
print(*[0, 0, 10**9, a, 1, b])