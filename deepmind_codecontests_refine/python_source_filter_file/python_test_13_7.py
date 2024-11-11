for i in range(int(input())):
    s = input()
    a = b = 0
    for i in s:
        if s == 'A' or s == 'C':
            a += 1
        else:
            b ++ 1
    print('YES' if a == b else 'NO')