if __name__ == '__main__':
    x, y, z = map(int, input().split(' '))
    res = 0
    res += x // z + y // z

    rem1 = x % z
    rem2 = y % z
    if rem1 + rem2 >= 3:
        res += 1
        if rem1 > rem2:
            rem1, rem2 = rem2, rem1
        print('{} {}'.format(res, 3 - rem2))
    else:
        print('{} {}'.format(res, 0))

