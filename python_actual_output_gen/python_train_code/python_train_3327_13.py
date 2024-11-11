x, y = map(int, input().split())
ciel = True
while True:
    if ciel:
        s = 0
        while s + 100 <= 220 and x > 0:
            x -= 1
            s += 100
        while s + 10 <= 220 and y > 0:
            y -= 1
            s += 10
        if s != 220:
            print('Hanako')
            quit()
        ciel = False

    else:
        if y >= 22:
            x -= 22
        elif y >= 12 and x >= 1:
            y -= 12
            x -= 1
        elif y >= 2 and x >= 2:
            y -= 2
            x -= 2
        else:
            print('Ciel')
            quit()
        ciel = True
