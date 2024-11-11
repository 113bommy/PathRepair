def main():
    n = int(input())
    print(
        0 if n < 11 else
        0 if n > 21 else
        15 if n == 21 else
        4
    )


if __name__ == '__main__':
    main()
