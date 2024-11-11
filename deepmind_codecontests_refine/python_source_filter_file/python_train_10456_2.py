def main():
    n, m = map(int, input().split())
    a = [[int(c) for c in input().split()] for _ in range(n)]

    if n % 2 == 1:
        print(n)
        return

    while n > 1:
        for i in range(n // 2):
            if a[i] != a[n - i - 1]:
                print(n)
                return

        n //= 2

    print(1)


if __name__ == "__main__":
    main()
