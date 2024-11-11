import math

n, k = map(int, input().split())
a = math.floor((n - 1) // 2 / (k + 1))
b = a * k
c = n - b - a
print(a, b, c)
