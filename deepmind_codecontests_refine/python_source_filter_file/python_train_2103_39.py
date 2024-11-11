import math
t = int(input())
while t:
    a, b, c, d, e = list(map(int, input().split()))
    m = math.ceil(a/c)+math.ceil(b/d)
    if m<=e:
        print(math.ceil(a/b),math.ceil(b/d))
    else:
        print(-1)
    t = t - 1