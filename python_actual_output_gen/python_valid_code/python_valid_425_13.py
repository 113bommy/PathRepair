for _ in range(int(input())):
    s = input()
    a = s.count('A')
    b = s.count('B')
    c = s.count('C')

    if a > 0 and b > 0 and c > 0:
        if b % (a + c) == 0:
            print('YES')
        else:
            print('NO')
    elif a > 0 and b > 0 and c == 0:
        if a == b:
            print('YES')
        else:
            print('NO')
    elif c > 0 and b > 0:
        if c == b:
            print('YES')
        else:
            print('NO')
    else:
            print('NO')