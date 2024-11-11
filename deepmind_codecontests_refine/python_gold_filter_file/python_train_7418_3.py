for _ in range(int(input())):
    n = int(input())
    if n<=30: print('NO')
    else:
        print('YES')
        if n-30 not in [14, 6, 10]: print('14 6 10', n-30)
        else: print('15 6 10', n-31)
