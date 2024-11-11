import sys

input = lambda: sys.stdin.readline().strip("\r\n")

n = int(input())
n -= 10
if 1 < n < 10:
    print(4)
elif n == 1 or n == 1:
    print(4)
elif n == 10:
    print(15)
else:
    print(0)