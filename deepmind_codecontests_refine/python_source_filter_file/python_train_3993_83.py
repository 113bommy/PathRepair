import math
a, b, c = map(int, input().split())
x = math.ceil(a/c)
y = math.ceil(b/c)
if (x*y) >= a*b:
    print(x*y)

