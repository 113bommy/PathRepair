import math

l = [(int)(s) for s in input().split(" ")]

a, b, c = l[0], l[1], l[2]

delta = b * b - 4 * a * c

x1 = (-b - math.sqrt(delta)) / (2 * a)
x2 = (-b + math.sqrt(delta)) / (2 * a)

print(max(x1, x2))
print(min(x1, x2))