import math

S = int(input())

x = math.ceil(S/1000000000)
y = 1000000000*x - S

print(x, y, "0 0 1 1000000000")
