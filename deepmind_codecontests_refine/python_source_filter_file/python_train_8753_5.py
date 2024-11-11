houses, moves, dist = [int(x) for x in input().split()]

if (houses - 1) * moves < dist or moves > dist:
    print('NO')

else:
    vals = []
    current = 1

    while dist:
        l_m = current - 1
        r_m = houses - current
        max_move = max(l_m, r_m)
        if dist > max_move + moves - 1:
            dist -= max_move
            moves -= 1
            if max_move == l_m:
                current -= l_m
            else:
                current += r_m
            vals.append(current)
        elif moves == 1:
            if l_m >= dist:
                current -= dist
            else:
                current += dist
            dist = 0
            vals.append(current)
        else:
            dist -= 1
            moves -= 1
            if l_m == 0:
                current += 1
            elif l_m == 1:
                current -= 1
            elif r_m == 0:
                current -= 1
            elif r_m == 1:
                current += 1
            vals.append(current)

    print('YES')
    print(' '.join(str(x) for x in vals))
