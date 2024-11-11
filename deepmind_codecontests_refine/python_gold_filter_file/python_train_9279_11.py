def main():
    from math import ceil, sqrt
    n, x, y = map(int, input().split())
    try:
        t = ceil(sqrt(max(x, y) - n + 1))
        print(str(t) + "\n1" * (n - 1) if 0 < t < y + 2 - n else -1)
    except ValueError:
        print(-1)


if __name__ == '__main__':
    main()
