from decimal import Decimal
a, b, c, d = map(Decimal, input().split())
previous = -1
current = 0
i = 0
q = a / b
r = c / d

while abs(current - previous) > 1e-7:
    previous = current
    current += q *( ((1 - r)*(1 - q)) ** i)
    i += 1
print(current)
