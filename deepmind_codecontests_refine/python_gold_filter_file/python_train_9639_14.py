def inp():
    return map(int, input().split())


x, y = inp()
ceil, hanako = 1, 0

while (True):
    if ceil:
        if x >= 2 and y >= 2:
            x -= 2
            y -= 2
        elif x == 1 and y >= 12:
            x -= 1
            y -= 12
        elif x == 0 and y >= 22:
            y -= 22
        else:
            exit(print('Hanako'))
        ceil, hanako = 0, 1
    else:
        if y >= 22:
            y -= 22
        elif y >= 12 and x >= 1:
            y -= 12
            x -= 1
        elif y >= 2 and x >= 2:
            y -= 2
            x -= 2
        else:
            exit(print('Ciel'))
        hanako, ceil = 0, 1
