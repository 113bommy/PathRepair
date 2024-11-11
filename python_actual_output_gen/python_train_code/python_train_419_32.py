a, b, c, d = [int(i) for i in input().split(' ')]
m = a / b
n = 1 - (1 - a / b) * (a - c / d)
print(m / n)
