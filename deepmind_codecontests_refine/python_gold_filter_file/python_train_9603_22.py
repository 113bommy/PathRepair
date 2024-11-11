import math
for _ in range(int(input())):
    a,b,c,d = map(int,input().split())
    if b >= a:
        print(b)
        continue

    if b < a:
        if d >= c:
            print(-1)

        else:
            som = b
            x = a-b
            y = abs(c-d)
            z = math.ceil(x/y)
            som = som+(z*(c))
            print(som)

