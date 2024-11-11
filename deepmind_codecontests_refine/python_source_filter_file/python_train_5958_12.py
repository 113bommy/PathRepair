def main():
    for _ in range(int(input())):
        n, g, b = map(int, input().split())
        m = (n + 1) // 2
        if m > g < b:
            n = m + b * ((m - 1) // g)
        print(n)


if __name__ == '__main__':
    main()
