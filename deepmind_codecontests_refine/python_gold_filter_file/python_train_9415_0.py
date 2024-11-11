def main():
    n, d = map(int, input().split())
    t = list(map(int, input().split()))
    sm = sum(t)
    if sm + 10*(n - 1) > d:
        print(-1)
    else:
        print((d - sm)//5)


if __name__ == "__main__":
    main()