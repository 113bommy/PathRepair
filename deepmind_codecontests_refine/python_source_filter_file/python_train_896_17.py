MaxN = 128


def read():
    return [int(v) for v in input().split()]


def main():
    n, m = read()

    a = []
    for _ in range(n):
        a.append(read())

    a.sort(key=lambda v: v[0])

    highest_val = 0
    for (start, end) in a:
        if start > highest_val:
            print('NO')
            return
        highest_val = max(highest_val, end)

    if highest_val <= m:
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    main()
