import math, sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input()) # remove 4 * e - 3
    e = math.floor((n - 3) / 4)
    print((n - e) * "9" + e * "8")
