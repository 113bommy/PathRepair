def main():
    a, b, c, d = map(int, input().split())
    if d <= c * 2 <= d * 4:
        print(a * 2, b * 2, max(c, d), sep='\n')
    else:
        print(-1)


if __name__ == '__main__':
    main()
