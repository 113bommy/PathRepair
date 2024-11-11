s = list(input())
hor, ver = False, False
for i in s:
    if i == '0':
        if not ver:
            print(3, 1)
            ver = True
        else:
            print(1, 1)
            ver = False
    else:
        if not hor:
            print(1, 3)
            hor = True
        else:
            print(1, 1)
            hor = False
