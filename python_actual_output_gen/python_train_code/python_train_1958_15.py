
def burger(b, p, f, h, c):
    b = b // 2
    if b >= p + f:
        return (p * h) + (f * c)
    elif  h > c:
        if b - p >= 0:
            return (p * h) + (b - p) * c
        else:
            return b * h
    elif c > h:
        if b - f >= 0:
            return (f * c) + (b - f) * h
        else:
            return b * f
    elif h == c:
        return (b * h)
    else:
        return 0
    # if b // 2 < 2:
    #     return 0
    # elif b // 2 <= (p + f):
    #     return (p*h + f*h)
    # else:
    #     if h < c:

n = int(input())
while n > 0:
    l = input().split(' ')
    b, p, f = int(l[0]), int(l[1]), int(l[2])
    l = input().split(' ')
    h, c = int(l[0]), int(l[1])
    print(burger(b, p, f, h, c))
    n -= 1