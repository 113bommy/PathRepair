x, y = map(int, input().split())
moves = 0
move = True
if x == 1000 and y == 1000: move = False
while move:
    if moves % 2 == 0:
        if x >= 2 and y >= 2:
            moves += 1
            x -= 2
            y -= 2
        elif x == 1 and y >= 12:
            moves += 1
            x -= 1
            y -= 12
        elif x == 0 and y >= 22:
            moves += 1
            y -= 22
        else:
            move = False
    elif moves % 2 == 1:
        if y >= 22:
            moves += 1
            y -= 22
        elif x == 1 and y >= 12:
            moves += 1
            x -= 1
            y -= 12
        elif x >= 2 and y >= 2:
            moves += 1
            x -= 2
            y -= 2
        else:
            move = False

ans = 'Ciel' if moves % 2 == 1 else 'Hanako'
if x == 1000 and y == 1000:
    print('Ciel')
else:
    print(ans)


