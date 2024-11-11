# Aizu Problem 0021: Parallelism
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


N = int(input())
for n in range(N):
    x1, y1, x2, y2, x3, y3, x4, y4 = [float(_) for _ in input().split()]
    det = (x2 - x1) * (y4 - y3) - (y2 - y1) * (x4 - x3)
    print("YES" if abs(det) < 1e-6  else "NO")