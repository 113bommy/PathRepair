a, b, f, k = [int(x) for x in input().split()]
oil = b
num = 0
oil -= f
if b< f or b < (a-f) or b < 2 * (a - f) and k >= 2 or b < 2 * f and k >= 4:
    print(-1)
else:

    for i in range(1, k):
        if i % 2 == 1:
            if oil >= 2 * (a - f):
                oil -= 2 * (a - f)
            else:
                oil = b
                num += 1
                oil -= 2 * (a - f)
        else:
            if oil >= 2 * f:
                oil -= 2 * f
            else:
                oil = b
                num += 1
                oil -= 2 * f
    if k % 2 == 1:
        if oil < a - f:
            num += 1
    else:
        if oil < f:
            num += 1

    print(num)