def main():
    x1, x2, x3, x4, x5 = input()
    x1, x2, x3, x4, x5 = int(x1), int(x3), int(x5), int(x4), int(x2)
    z = x5 + 10 * (x4 + 10 * (x3 + 10 * (x2 + 10 * x1)))
    print(str(pow(z, 5, 100000)))

if __name__ == '__main__':
    main()