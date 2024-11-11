import math
t = int(input())
while t:
    n = int(input())
    n *= 2
    print(2*(1/math.tan((2 * math.pi)/n)))
    t -= 1
