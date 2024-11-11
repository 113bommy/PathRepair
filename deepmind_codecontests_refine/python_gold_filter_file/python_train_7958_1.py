n = int(input())

if n < 4:
    print('NO')
elif n == 5:
    print('YES')
    print('5 * 4 = 20')
    print('20 + 3 = 23')
    print('23 + 2 = 25')
    print('25 - 1 = 24')
elif n == 4:
    print('YES')
    print('1 * 2 = 2')
    print('2 * 3 = 6')
    print('6 * 4 = 24')
else:
    if ((n - 4) % 2) == 0:
        print('YES')
        for i in range(n, 4, -2):
            print('%s - %s = %s' %(i, i-1, 1))
        print('1 * 2 = 2')
        print('2 * 3 = 6')
        print('6 * 4 = 24')
        for i in range(n, 4, -2):
            print('1 * 24 = 24')
    else:
        print('YES')
        print('%s - 1 = %s' % (n, n-1))
        print('%s - %s = 0' % (n-1, n-1))
        for i in range(n - 2, 4, -1):
            print('%s * 0 = 0' %(i))
        print('2 * 3 = 6')
        print('6 * 4 = 24')
        print('24 + 0 = 24')



