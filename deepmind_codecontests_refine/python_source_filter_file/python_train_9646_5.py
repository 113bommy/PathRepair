nm = input()

if(nm == '1') | (nm == '0'):
    print(0)
    raise SystemExit


a = []

pos = 0

for i in range(44722):
    a.append(i * i)

# for i in range(44722):
#     print(a[i])
i = 1
max = 0

for i in range(44721, 1, -1):
    if (len(str(a[i])) != len(str(nm))):
        i = i * 10

    else:
        pos = i
        pn = a[i]
        # print(pos)
        # print(pn)
        break

flag1 = False
flag2 = False


for i in range(pos, 0, -1):
    spn = str(a[i])
    snm = str(nm)
    if (spn == '1'):
        # print('Нужный квадрат:')
        # # print(a[i], '=', i, '*', i)
        # print()
        # print('Наше число:')
        # print(nm)
        # print()
        # print('Кол-во символов для удаления:')
        print(len(snm) - len(spn))
        exit()
    for j in range(len(spn)):
        for k in range(len(snm)):
            if (len(snm) - k >= len(spn) - j):

                if (spn[j] == snm[k]):
                    if (j + 1 == len(spn)):
                        # print('Нужный квадрат:')
                        # print(a[i], '=', i, '*', i)
                        # print()
                        # print('Наше число:')
                        # print(nm)
                        # print()
                        # print('Кол-во символов для удаления:')
                        print(len(snm) - len(spn))
                        exit()
                    j = j + 1
                    continue
                else:
                    if (k + 1 == len(snm)):
                        flag1 = True
                    continue




            else:
                flag1 = True
                break

        if (flag1 == True):
            break

    if (flag1 == True):
        flag1 = False
        continue

    # print('Нужный квадрат:')
    # print(a[i], '=', i, '*', i)
    # print()
    # print('Наше число:')
    # print(nm)
    # print()
    # print('Кол-во символов для удаления:')
    print(len(snm) - len(spn))
    exit()



print(-1)
