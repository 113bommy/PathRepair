from math import sqrt
a, b, c = [int(i) for i in input().split()]
x1 = ((b * -1 - sqrt(b ** 2 - 4 * a * c)) / (2 * a))
x2 = ((b * -1 + sqrt(b ** 2 - 4 * a * c)) / (2 * a))
print(min(x1, x2), max(x1, x2), sep="/n")