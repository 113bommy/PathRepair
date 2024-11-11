import sys
n = int(sys.stdin.readline())
print((pow(2, n, 5) + pow(3, n, 5) + pow(4, n, 5)) % 5)