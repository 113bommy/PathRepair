import sys

for line in sys.stdin:
    d = int(line)
    S = 0
    for x in range(1, 600, d):
        S += (x ** 2) * d
    print(S)