import math
t = int(input())
while t:
    a, b, c, d, e = list(map(int, input().split()))
    m = math.ceil(a/b)+math.ceil(c/d)
    if m<=e:
        print(e-math.ceil(c/d),math.ceil(c/d))
    else:
        print(-1)
    t = t - 1