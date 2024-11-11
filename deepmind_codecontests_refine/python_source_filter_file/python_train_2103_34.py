from math import ceil
t = int(input())
for _ in range(t):
    a, b, c, d, k = map(int, input().split())
    x = ceil(a+c-1//c)
    y = ceil(b+d-1//d)
    if x + y <= k:
        print("{} {}".format(x, y))
    else:
        print(-1)
