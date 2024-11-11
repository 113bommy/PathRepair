import operator

LEN = 50
HALF = 25

numbers1 = input().split(" ")
dic = {}
dic['A'] = int(numbers1[0])
dic['B'] = int(numbers1[1])
dic['C'] = int(numbers1[2])
dic['D'] = int(numbers1[3])
tmp = sorted(dic.items(), key=operator.itemgetter(1), reverse=True)
dic = dict(tmp)
sol = [[None for _ in range(LEN)] for _ in range(LEN)]
for i in range(HALF):
    for j in range(HALF):
        if i % 2 == 0 and j % 2 == 1 and dic['D'] - 1 > 0:
            sol[i][j] = 'D'
            dic['D'] -= 1
        else:
            sol[i][j] = 'A'
for i in range(HALF):
    for j in range(HALF, LEN):
        if i % 2 == 0 and j % 2 == 1 and dic['C'] - 1 > 0:
            sol[i][j] = 'C'
            dic['C'] -= 1
        else:
            sol[i][j] = 'B'
for i in range(HALF, LEN):
    for j in range(HALF):
        if i % 2 == 0 and j % 2 == 1 and dic['B'] - 1 > 0:
            sol[i][j] = 'B'
            dic['B'] -= 1
        else:
            sol[i][j] = 'C'
for i in range(HALF, LEN):
    for j in range(HALF, LEN):
        if i % 2 == 0 and j % 2 == 1 and dic['A'] - 1 > 0:
            sol[i][j] = 'A'
            dic['A'] -= 1
        else:
            sol[i][j] = 'D'
print(50, 50)
for i in range(LEN):
    for j in range(LEN):
        print(sol[i][j], end=' ')
    print()
