# Aizu Problem 0080: Third Root
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


def third_root(q):
    x = q / 2
    while abs(x**3 - q) > 1e-5:
        x = x - (x**3 - q) / (3 * x**2)
    return x


for line in sys.stdin:
    n = int(line)
    if n == -1:
        break
    print("%.6f" % third_root(n))