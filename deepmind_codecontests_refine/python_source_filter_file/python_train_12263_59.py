s =int(input())
if s % 25 == 0 or s % 25 == 13:
    print(':(')
else:
    print((-s * 25 // 27) * (-1))