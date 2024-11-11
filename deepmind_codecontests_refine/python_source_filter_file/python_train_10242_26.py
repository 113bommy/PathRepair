arr = []

for i in range(3):
    arr.append(input().split(' '))

res = [['1', '1', '1'] for i in range(3)]

for i in range(3):
    for j in range(3):
        if arr[i][j] != '0':
            if int(arr[i][j]) % 2 == 0:
                pass
            else:
                if res[i][j] == '1':
                    res[i][j] = '0'
                else:
                    res[i][j] = '1'
                if i + 1 < 3:
                    if res[i + 1][j] == '1':
                        res[i + 1][j] = '0'
                    else:
                        res[i + 1][j] = '1'
                if i - 1 >= 0:
                    if res[i - 1][j] == '1':
                        res[i - 1][j] = '0'
                    else:
                        res[i - 1][j] = '1'
                if j + 1 < 3:
                    if res[i][j + 1] == '1':
                        res[i][j + 1] = '0'
                    else:
                        res[i][j + 1] = '1'
                if j - 1 >= 0:
                    if res[i][j - 1] == '1':
                        res[i][j - 1] = '0'
                    else:
                        res[i][j - 1] = '1'


for i in res:
    print(*i)