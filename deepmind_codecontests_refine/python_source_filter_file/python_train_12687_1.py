import sys

a, b = [], []
for line in sys.stdin:
    x, y = map(int, line.strip().split(","))
    a, b = a+[x*y], b+[y]
print(sum(a))
print(round(sum(b)/len(b)))