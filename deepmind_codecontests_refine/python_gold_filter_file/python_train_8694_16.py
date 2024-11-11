import math

a, b, c = map(lambda x: int(x), input().split(' '))

d = b ** 2 - 4 * a * c

x1, x2 = max((- b + d ** 0.5) / 2 / a, (- b - d ** 0.5) / 2 / a), min((- b + d ** 0.5) / 2 / a, (- b - d ** 0.5) / 2 / a)

print(x1, x2)
