def main():
    for _ in range(int(input())):
        n, k = map(int, input().split())
        a, *bb = map(int, input().split())
        r = a * 2 - 1
        for b in bb:
            if r < b - a:
                r = b - a
            a = b
        if r < (n - a) * 2 + 1:
            r = (n - a) * 2 + 1
        print((r + 1) // 2)


if __name__ == '__main__':
    main()
