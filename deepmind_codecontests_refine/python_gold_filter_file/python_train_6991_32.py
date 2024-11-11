x, y, z = map(int, input().split())

if x + z < y:
    print('-')
elif z + y < x:
    print('+')
else:
    if z == 0:
        print('-' if x < y else ('+' if x > y else '0'))
    else:
        print('?')
