def main():
    n = int(input())
    f = list(map(int, input().split()))
    out = 0
    for i in range(n):
        out += f[i]/100/n
    print(out)


if __name__ == '__main__':
    main()
