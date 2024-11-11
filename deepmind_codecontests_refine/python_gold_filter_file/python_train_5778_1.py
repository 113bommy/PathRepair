def main():
    a1, a2, a3, a4, a5, a6 = map(int, input().split())
    print((a1 + a6) * (a5 + a6) * 2 - a6 * a6 - a3 * a3)


if __name__ == '__main__':
    main()
