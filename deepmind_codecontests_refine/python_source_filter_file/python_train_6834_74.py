n = int(input())
if n > 36:
    print(-1)
else:
    if n % 2 == 1:
        print('8' + ('4' * (n // 2)))
    else:
        print('8' * (n // 2))