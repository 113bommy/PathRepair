# Aizu Problem 0054: Sum of Nth Decimal Places
#
import sys, math, os, bisect

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


for line in sys.stdin:
    a, b, n = [int(_) for _ in line.split()]
    frac = str(round(a / b, 10)).split('.')[1]
    print(sum([int(d) for d in frac[:n]]))