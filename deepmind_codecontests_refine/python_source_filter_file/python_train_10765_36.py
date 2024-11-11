n = int(input())

if n == 0:
    print('O-|-OOOO')
else:
    while n > 0:
        d = n % 10
        n = n // 10
        print(('-O', 'O-')[n < 5] + '|', end='')
        d = d % 5
        print('O' * d + '-' + 'O' * (4 - d))
