def read_nums():
    return [int(x) for x in input().split()]


def print_res(l, r):
    for x in range(l, r):
        for y in range(x, r, x):
            if x == y:
                continue
            if y % x == 0:
                print(x, y)
                return


def main():
    t, = read_nums()
    for _ in range(t):
        l, r = read_nums()
        print_res(l, r)


if __name__ == '__main__':
    main()
