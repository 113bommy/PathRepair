import math
t = int(input())
for i in range(t):
    a, b, k = map(int, input().split())
    if a == b:
        if k % 2 == 0:
            print(0)
        else:
            print(1)
    else:
        x = 0
        v = int(math.ceil(k/2))
        if k % 2 == 0:
            x += v*a
            x -= v*b
            print(x)
        else:
            x += v * a
            x -= (v-1) * b
            print(x)
