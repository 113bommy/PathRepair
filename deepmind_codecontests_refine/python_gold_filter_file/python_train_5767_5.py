t, s_x, s_y, e_x, e_y = list(map(int, input().strip().split()))
wind = input()

x = e_x - s_x
y = e_y - s_y

ctr = 0
for w in wind:
    if x == 0 and y == 0:
        break
    else:
        if w == 'N' and y > 0:
            y -= 1
        elif w == 'S' and y < 0:
            y += 1
        elif w == 'E' and  x > 0:
            x -= 1
        elif w == 'W' and x < 0:
            x += 1
    ctr += 1

print(ctr if (x == 0 and y == 0) else -1)
