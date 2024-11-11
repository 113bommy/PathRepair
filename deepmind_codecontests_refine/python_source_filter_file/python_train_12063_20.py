import sys
import math

for line in sys.stdin:
    a, b = map(int, line.split())
    print(int(math.log(a + b, 10) + 1))