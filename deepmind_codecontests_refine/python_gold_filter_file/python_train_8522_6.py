import sys
f = sys.stdin

a, b = map(int, f.readline().split())
print('{:.6f}'.format(a * b / 3.305785))