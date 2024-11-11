def main():
    res, n = divmod(int(input()), 2520)
    l = [1] * n
    for p in range(2, 11):
        for i in range(0, n, p):
            l[i] = 0
    print(res * 576 + sum(l))


if __name__ == '__main__':
    main()
