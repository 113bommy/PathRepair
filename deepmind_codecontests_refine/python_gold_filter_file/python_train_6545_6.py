import sys

for l in sys.stdin.readlines():
    data = l.split(",")
    x, y = float(data[1]), float(data[2])
    if 25.0 <= x / y ** 2:
        print(data[0])