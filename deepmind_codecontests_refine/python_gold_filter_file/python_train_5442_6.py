n = int(input())

i = 0
while i < n:
    _ = input()
    ch = input()
    mas = [0, 0, 0, 0]
    for j in range(len(ch)):
        if (j + 1) % 2 == 0 and int(ch[j]) % 2 == 0:
            mas[0] += 1
        elif (j + 1) % 2 == 0 and int(ch[j]) % 2 != 0:
            mas[1] += 1
        elif (j + 1) % 2 != 0 and int(ch[j]) % 2 == 0:
            mas[2] += 1
        elif (j + 1) % 2 != 0 and int(ch[j]) % 2 != 0:
            mas[3] += 1

    if mas[0] + mas[1] < mas[2] + mas[3]:
        if mas[3] > 0:
            print('1')
        else:
            print('2')
    else:
        if mas[0] > 0:
            print('2')
        else:
            print('1')
    i += 1