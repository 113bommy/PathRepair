def main():
    n, mod = int(input()), 1000007
    print((pow(27, n, mod) - pow(7, n, mod)) % mod)


if __name__ == '__main__':
    main()
