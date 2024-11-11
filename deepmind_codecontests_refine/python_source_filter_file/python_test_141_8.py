from math import e


t = int(input())
for _ in range(t):
    a, s = input().split()
    b = []
    exists = True
    while len(s) > 0:
        if len(a) > len(s):
            exists = False
            break

        if len(a) == 0:
            for i in reversed(s):
                b.insert(0, i)
            break

        if int(a[-1]) > int(s[-1]):
            enter = int(s[-2:]) - int(a[-1])
            if enter <= 9:
                b.insert(0,  str(enter))
                s = s[:-2]
                a = a[:-1]
            else:
                exists = False
                break

        else:
            b.insert(0, str(int(s[-1]) - int(a[-1])))
            s = s[:-1]
            a = a[:-1]

    if exists:
        b = ''.join(b)
        if len(b) == 1:
            print(b)
        else:
            b = b.lstrip('0')
            print(b)
    else:
        print(-1)
