def main():
    *l, k = map(int, input().split())
    x, y, z = sorted(l)
    x = min(k // 3 + 1, x)
    y = min((k - x + 1) // 2 + 2, y)
    z = min(k - x - y + 3, z)
    print(x * y * z)


if __name__ == '__main__':
    main()
