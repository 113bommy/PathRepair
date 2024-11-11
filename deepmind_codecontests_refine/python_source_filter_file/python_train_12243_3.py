def main():
    h, m = map(int, input().split(':'))
    for i in range(99):
        if "%02d" % h == ("%02d" % m)[::-1]:
            break
        h, m = divmod(h * 60 + m + 1, 60)
        h %= 24
    print(i)


if __name__ == '__main__':
    main()
