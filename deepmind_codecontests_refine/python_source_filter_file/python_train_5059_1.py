def test(s, p):
    i = (s // 50) % 475
    for _ in range(25):
        i *= 96
        i += 42
        i %= 475
        if i + 26 == p:
            return True

    return False


def main():
    p, x, y = map(int, input().split())

    s = x + ((y - x) // 50) * 50
    for _ in range(475):
        if test(s, p):
            break
        s += 50

    if s <= x:
        print(0)
    else:
        d = (s - x) // 50
        print((d + 1) // 2)


if __name__ == '__main__':
    main()
