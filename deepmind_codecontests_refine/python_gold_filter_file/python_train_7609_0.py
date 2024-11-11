def read():
    return [int(v) for v in input().split()]


def min_stolen(a):
    n = len(a)
    ans = 0
    for i in range(1, n):
        ans += a[i] - a[i-1] - 1
    return ans


def main():
    read()
    a = sorted(read())
    print(min_stolen(a))


if __name__ == '__main__':
    main()