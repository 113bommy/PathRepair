def main():
    n, r = int(input()), 0
    for c in 100, 50, 20, 10, 5, 1:
        r += n // c
        n %= c
    print(r)


if __name__ == '__main__':
    main()
