s = input()
try:
    if s.count('-') % s.count('o') == 0:
        print('YES')
    else:
        print('NO')
except ZeroDivisionError:
    print('NO')
