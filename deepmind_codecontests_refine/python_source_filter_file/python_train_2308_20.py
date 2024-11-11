from math import fabs
def u(x):
    if x <= 0:
        return 0
    return x
a, b, c, d = list(map(int, input().split()))
m = sorted([a, b, c])
print(u(d - fabs(m[1] - m[0])) + u(d - fabs(m[2] - m[1])))