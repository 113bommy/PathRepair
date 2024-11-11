def read_nums():
    return [int(x) for x in input().split()]


def solve(n):
    res = 0
    while True:
        if n < 1:
            return -1
        if n == 1:
            break
        elif n % 5 == 0:
            n = 4 * n / 5
            res += 1
        elif n % 3 == 0:
            n = 2 * n / 3
            res += 1
        elif n % 2 == 0:
            n = n / 2
            res += 1
        else:
            return -1
    return res


def main():
    q, = read_nums()
    for _ in range(q):
        print(solve(int(input())))


if __name__ == '__main__':
    main()
