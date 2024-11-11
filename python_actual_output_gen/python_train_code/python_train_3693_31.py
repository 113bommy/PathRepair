
n = int(input())

if n == 0:
    print('O-|-OOOO')
else:
    while n > 0:
        d = n % 10
        n = n // 10
        print(('0-', '-0')[n < 5] + '|', end='')
        d = d % 5
        print('0' * d + '-' + '0' * (4 - d))
