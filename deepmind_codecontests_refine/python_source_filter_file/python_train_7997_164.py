import sys

x, y = list(map(abs, list(map(int, input().split()))))

if y % x == 0:
    print(-1)
else:
    print(x)