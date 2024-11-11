# Aizu Problem 0076: Treasure Hunt II
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


positions = {0: [0, 0], 1: [1, 1]}
direction = 135 * math.pi / 180
x, y = 1, 1
for step in range(2, 10):
    x += math.cos(direction)
    y += math.sin(direction)
    positions[step] = [x, y]
    direction = math.atan2(x, -y)

while True:
    n = int(input())
    if n == -1:
        break
    print("%.2f" % positions[n-1][0])
    print("%.2f" % positions[n-1][1])
    