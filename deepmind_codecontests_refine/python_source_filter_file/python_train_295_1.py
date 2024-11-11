import sys

c1 = c2 = 0
for line in sys.stdin:
    a, b, c = map(int, line.split(','))
    if a**2 + b**2 == c**2:
        c1 += 1
    elif a == b:
        c2 += 1
print(c1, c2)