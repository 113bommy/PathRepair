def main():
    n = int(input())
    s = input()

    try:
        index = next(i for i in range(n - 1) if s[i] > s[i + 1])
        print('YES\n%d %d' % (index, index + 1))
    except StopIteration:
        print('NO')


if __name__ == '__main__':
    main()
