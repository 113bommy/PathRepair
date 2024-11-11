n = input()

if n == 0:
    print(4)
else:
    d = int(n[-2:])

    if d % 4 == 0:
        print(1)
    elif d % 4 == 1 or d % 4 == 2 or d % 4 == 3:
        print(0)
    else:
        print(3)