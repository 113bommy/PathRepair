def main():
    n, m, k = map(int, input().split())
    if 0 <= k < n:
        r = k + 1
        c = 1
    else:
        p = k - (n - 1)
        x, y = divmod(p, m - 1)
        x = x if y == 0 else x - 1
        if x % 2 == 1:
            c = m if y == 0 else y + 1
        else:
            c = 2 if y == 0 else m - (y - 1)
        r = n - x + 1
    print(r,c)


if __name__ == '__main__':
    main()