def main():
    n = int(input())
    for _ in range(1, 5):
        a, b, c, d = map(int, input().split())
        for x, y in (a, c), (a, d), (b, c), (b, d):
            if x + y <= n:
                print(_, x, n - x)
                return
    print(-1)


if __name__ == '__main__':
    main()