n = int(input())
need = []
smth = []
for i in range(n):
    s = ''
    for j in range(n):
        if i % 2 == 0:
            if j % 2 == 0:
                s += '1'
            else:
                s += '0'
        else:
            if j % 2 == 1:
                s += '1'
            else:
                s += '0'
    smth.append(s)
need.append(smth)
smth = []
for i in range(n):
    s = ''
    for j in range(n):
        if i % 2 == 0:
            if j % 2 == 0:
                s += '0'
            else:
                s += '1'
        else:
            if j % 2 == 1:
                s += '0'
            else:
                s += '1'
    smth.append(s)
need.append(smth)
kolvo = []
for i in range(4):
    a = []
    now = []
    sum1 = 0
    sum2 = 0
    for j in range(n):
        s = input()
        now.append(s)
    for x in range(len(now)):
        for y in range(len(now[x])):
            if x % 2 == 0:
                if y % 2 == 0 and now[x][y] == '0':
                    sum1 += 1
                elif y % 2 == 1 and now[x][y] == '1':
                    sum1 += 1
            else:
                if y % 2 == 0 and now[x][y] == '1':
                    sum1 += 1
                elif y % 2 == 1 and now[x][y] == '0':
                    sum1 += 1
    a.append(sum1)
    for x in range(len(now)):
        for y in range(len(now[x])):
            if x % 2 == 0:
                if y % 2 == 0 and now[x][y] == '1':
                    sum2 += 1
                elif y % 2 == 1 and now[x][y] == '0':
                    sum2 += 1
            else:
                if y % 2 == 0 and now[x][y] == '0':
                    sum2 += 1
                elif y % 2 == 1 and now[x][y] == '1':
                        sum2 += 1
    a.append(sum2)
    kolvo.append(a)
    if i != 3:
        s = input()
ans = 10000000000000000000000000000000000000000000000000000000000000000
for i in range(len(kolvo) - 1):
    for j in range(i + 1, len(kolvo[i])):
        ind = []
        for z in range(len(kolvo)):
            if z != i and z != j:
                ind.append(z)
        x = ind[0]
        y = ind[1]
        if kolvo[i][0] + kolvo[j][0] + kolvo[x][1] + kolvo[y][1] < ans:
            ans = kolvo[i][0] + kolvo[j][0] + kolvo[x][1] + kolvo[y][1]
for i in range(len(kolvo) - 1):
    for j in range(i + 1, len(kolvo[i])):
        ind = []
        for z in range(len(kolvo)):
            if z != i and z != j:
                ind.append(z)
        x = ind[0]
        y = ind[1]
        if kolvo[i][1] + kolvo[j][1] + kolvo[x][0] + kolvo[y][0] < ans:
            ans = kolvo[i][1] + kolvo[j][1] + kolvo[x][0] + kolvo[y][0]
print(ans)
        