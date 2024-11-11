def main():
    a, b, c = map(int, input().split())
    res, flag = [], (a + b + c) & 1
    for x, y, z in (a, b, c), (b, c, a), (c, a, b):
        xy = (x + y - z) // 2
        flag |= xy < 0
        res.append(xy)
    if flag:
        print('Impossible')
    else:
        print(*res)


if __name__ == '__main__':
    main()