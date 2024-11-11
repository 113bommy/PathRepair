import math

x, y, X, Y = [int(i) for i in input().split()]
print(math.sqrt((x-X)**2 + abs(y-Y)**2))