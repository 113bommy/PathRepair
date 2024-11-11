import sys

data = [float(x) for x in sys.stdin.readline().strip().split()]
print((data[1]**2 - data[0]**2)/data[0])