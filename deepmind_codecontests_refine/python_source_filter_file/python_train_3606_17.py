import math


def is_sqrt(y):
    if y < 0:
        return False
    elif y == 0:
        return True
    x = int(math.sqrt(y))
    return x * x == y


m = -1
n = int(input())
ints = list(map(int, input().split()))
for z in ints:
    if not is_sqrt(z) and z > m:
        m = z

print(m)
