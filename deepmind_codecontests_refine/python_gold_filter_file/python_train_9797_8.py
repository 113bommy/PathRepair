def main():
    n, k = map(int, input().split())
    m = k * 2 + 1
    x, y = divmod((n + m - 1), m)
    print(x, ' '.join(map(str, range(y // 2 + 1, n + 1, m))), sep='\n')


if __name__ == '__main__':
    main()
