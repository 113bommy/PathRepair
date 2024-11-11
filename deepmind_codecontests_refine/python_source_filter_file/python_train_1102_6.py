import sys

lines = int(sys.stdin.readline())
for _ in range(lines):
    a, b = map(float, sys.stdin.readline().split(' '))
    if b == 0.0:
        print(1)
    elif a <= 4*b:
        print((0.125*a + b) / (2.0*b))
    else:
        print(a - b)
