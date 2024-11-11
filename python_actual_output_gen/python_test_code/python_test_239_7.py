h1, h2 = map(int, input().split())
a, b = map(int, input().split())
h1 += a * 8
if h1 >= h2:
    print(0)
else:
    h1 -= b * 12
    if b >= a:
        print(-1)
    else:
        day = 0
        while True:
            day += 1
            h1 += a * 4
            if h1 >= h2:
                print(-1)
                break
            h1 += a * 8
            if h1 >= h2:
                print(day)
                break
            h1 -= b * 12