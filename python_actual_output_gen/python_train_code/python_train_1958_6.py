t = int(input())
d = 0
for i in range(t):
    b, p, f = map(int, input().split())
    h, c = map(int, input().split())
    if c >= h:
        while b >= 2  and f >= 1:
            b -= 2
            f -= 1
            d += c
        while b >= 2  and p >= 1:
            b -= 2
            p -= 1
            d += h
    else:
        while b >= 2  and p >= 1:
            b -= 2
            p -= 1
            d += c
        while b >= 2  and f >= 1:
            b -= 2
            f -= 1
            d += h
    print(d)
    d = 0