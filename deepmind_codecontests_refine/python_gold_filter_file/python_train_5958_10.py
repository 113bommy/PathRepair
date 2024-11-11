import math


t = int(input())
for _ in range(t):
    n, g, b = map(int, input().split())
    good = math.ceil(n / 2)
    bad = 0
    if good / g - good // g == 0:
        bad = good // g - 1
    else:
        bad = good // g
    ans = bad * b + good
    if g >= n or g >= good:
        print(n)
    elif ans >= n:
        print(int(ans))
    else:
        print(int(n))
