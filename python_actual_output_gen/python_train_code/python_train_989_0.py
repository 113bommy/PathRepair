a = int(input())
f = s = 0
if a % 7 == 0:
    print('7' * (a // 7), end = '')
else:
    while True:
        a -= 7
        f += 1
        if a % 4 == 0:
            s = a // 4
            break
        if a < 0:
            print(-1)
            exit()
        if a == 0:
            break
    print('4' * s, end = '')
    print('7' * f, end = '')