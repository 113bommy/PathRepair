conf = [[int(num) for num in input().split()] for i in range(4)]

bad = False
for ind in range(4):
    bad |= conf[ind][3] and (1 in conf[ind][:3] or
                             conf[(ind + 1) % 4][0] or
                             conf[(ind + 2) % 4][1] or
                             conf[(ind + 3) % 4][2])

print('YES' if bad else 'NO')
