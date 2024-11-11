n = int(input())
if n <= 3:
    print('NO')
    exit(0)
print('YES')
if n % 2 == 0:
    for i in range(6, n+2, 2):
        print('{0} - {1} = 1'.format(i, i-1))
        print('1 * 1 = 1')
    print('1 * 2 = 2')
    print('2 * 3 = 6')
    print('6 * 4 = 24')
else:
    for i in range(5, n+2, 2):
        print('{0} - {1} = 1'.format(i, i-1))
        print('1 * 1 = 1')
    print('4 * 5 = 20')
    print('20 + 3 = 23')
    print('23 + 2 = 25')
    print('25 - 1 = 24')