def main():
    n, a, b, c, d = map(int, input().split())

    for i in range(n):
        if c * (n-1-i) - d * i <= b - a <= -c * i + d * (n-1-i):
            print("Yes")
            break
    else:
        print("No")


if __name__ == '__main__':
    main()
