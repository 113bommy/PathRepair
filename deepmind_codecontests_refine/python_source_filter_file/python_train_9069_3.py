s = list(input())
hor, ver = False, False
for i in s:
    if i == '0':
        if not ver:
            print(4, 1)
            ver = True
        else:
            print(1, 1)
            ver = False
    else:
        if not hor:
            print(1, 4)
            hor = True
        else:
            print(1, 1)
            hor = False
