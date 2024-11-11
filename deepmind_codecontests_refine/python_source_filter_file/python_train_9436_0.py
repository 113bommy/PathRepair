all = []
for i in range(6):
    all.append(''.join(input().split('-')))
good = [[3, 3, 4, 4, 3, 3],
        [3, 3, 4, 4, 3, 3],
        [2, 2, 3, 3, 2, 2],
        [2, 2, 3, 3, 2, 2],
        [1, 1, 2, 2, 1, 1],
        [1, 1, 2, 2, 1, 1]]
m = 0
mi = [0, 0]
for i in range(6):
    for j in range(6):
        if all[i][j] == '.' and good[i][j] > m:
            m = good[i][j]
            mi = [i, j]
all[mi[0]] = all[mi[0]][:mi[1]]+'P'+all[mi[0]][mi[1]:]
for i in range(6):
    print(all[i][0]+all[i][1]+'-'+all[i][2]+all[i][3]+'-'+all[i][4]+all[i][5])