def busgame(x,y):
    while 1:
        if x >= 2 and y >= 2:
            x -= 2
            y -= 2
        elif x == 1 and y >= 12:
            x -= 1
            y -= 12
        elif x == 0 and y >= 22:
            y -= 22
        else:
            return 'Hannako'

        if y >= 22:
            y -= 22
        elif 22 > y >= 12 and x >= 1:
            y -= 12
            x -= 1
        elif y < 12 and x >= 2:
            y -= 2
            x -= 2
        else:
            return 'Ciel'



x, y = [int(x) for x in input().split()]
print(busgame(x,y))