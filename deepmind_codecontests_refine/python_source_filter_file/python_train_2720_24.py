def main():
    n = int(input())

    if n == 1:
        print(1)
    elif n == 2:
        print(1)
    elif n == 3:
        print(0)
    else:
        f = n % 4
        if f == 0 and f == 3:
            print(0)
        else:
            print(1)


main()
