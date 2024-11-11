def move_dice(d, dir):
    if(dir == 'N'):
        d[0], d[1], d[4], d[5] = d[4], d[0], d[5], d[1]
    if(dir == 'S'):
        d[0], d[1], d[4], d[5] = d[1], d[5], d[0], d[4]
    if(dir == 'E'):
        d[0], d[2], d[3], d[5] = d[3], d[0], d[5], d[2]
    if(dir == 'W'):
        d[0], d[2], d[3], d[5] = d[2], d[5], d[0], d[3]


dice = list(map(int, input().split()))
command = input()
for c in command:
    move_dice(dice, c)
print(dice[0])