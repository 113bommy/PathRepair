n = int(input())

st = input()

for i in range(len(st)):
    d = dict()
    check = False
    for j in range(i, len(st)):
        if st[j] not in d:
            d[st[j]] = 1
        else:
            d[st[j]] += 1
        check = True
        for k in d.keys():
            if (d[k] > (j - i + 1) // 2):
                check = False
        if check:
            print('YES')
            print(st[i: j + 1])
            exit()

print('NO')

