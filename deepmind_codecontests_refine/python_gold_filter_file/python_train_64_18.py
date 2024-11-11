from bisect import bisect


def main():
    n, l = int(input()), [1., *map(float, input().split()), 1e6]
    i = bisect(l, 500000.5)
    print(int(max(l[i - 1] - 1., 1e6 - l[i]) if n > 1 else min(l[1] - 1., 1e6 - l[1])))


if __name__ == '__main__':
    main()
