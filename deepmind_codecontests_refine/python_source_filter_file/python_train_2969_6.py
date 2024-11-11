__author__ = 'olymp'


def main():
    a = input().strip()
    if a[1] == " ":
        day = int(a[0])
    else:
        day = int(a[0:2])
    if "month" in a:
        if day <= 29:
            ans = 12
        elif day == 30:
            ans = 11
        else:
            ans = 8
    else:
        if day == 5 or day == 6:
            ans = 53
        else:
            ans = 52
    print(ans)


if __name__ == '__main__':
    main()