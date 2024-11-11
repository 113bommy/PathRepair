import math

t = int(input())

for w in range(t):
    a, b, c, d, k = [int(i) for i in input().split()]

    if k - (math.ceil(a / c) + math.ceil(b // d)) > -1:
        print(math.ceil(a / c), math.ceil(b / d))
    else:
        print(-1)