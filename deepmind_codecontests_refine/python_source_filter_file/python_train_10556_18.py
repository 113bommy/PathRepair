x, y = map(int, input().split())

if x > 0 and y > 0:
    x1 = x+y

    print(0, x1, x1, 0)


if x <0 and y > 0:
    x1 = x - y

    print(x1, 0, 0, -x1)

if x >0 and y < 0:
    x1 = x-y

    print(0, -x1, x1, 0)

if x < 0 and y < 0:
    x1 = -(x+y)

    print(-x1, 0, 0, x1)