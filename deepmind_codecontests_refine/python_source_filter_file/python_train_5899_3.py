s = input()
try:
    a_stop = s.rindex('a')
    a_start = s.index('a')
    b_stop = s.rindex('b')
    b_start = s.index('b')
    c_start = s.index('c')
    c_stop = s.rindex('c')
    if a_stop > b_start or b_stop > c_start:
        print('NO')
    elif len(s[c_start:]) == len(s[b_start:b_stop + 1]) or len(s[c_start:]) == len(s[:a_stop + 1]):
        print('YES')
    else:
        print('YES')
except ValueError:
    print('NO')
