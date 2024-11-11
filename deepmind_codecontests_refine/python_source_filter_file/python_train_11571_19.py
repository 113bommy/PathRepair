def main():
    n, v = map(int, input().split())
    n -= 1
    if v >= n:
        print(v)
        return
    p = (1 + n - v)*(2 + n - v) // 2 + v - 1
    print(p)


if __name__ == '__main__':
    main()
