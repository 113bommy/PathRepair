x, y, z = map(int, input().split())

if x + y < z:
    print('-')
elif z + y < x:
    print('+')
else:
    if y == 0:
        print('-' if x < z else ('+' if x > z else '0'))
    else:
        print('?')
