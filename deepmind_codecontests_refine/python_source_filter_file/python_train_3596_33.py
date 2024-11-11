def main():
    x, n = map(int, input().split())
    distressed = 0
    for i in range(x):
        k = input()
        if k[0] == '+':
            n += int(k[1:])
        else:
            if int(k[1:]) < n:
                n -= int(k[1:])
            else:
                distressed += 1
    print(n, distressed, sep=' ')


if __name__ == '__main__':
    main()
