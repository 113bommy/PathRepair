string = input()


def main():
    for i in string:
        if i in "HQ9+":
            return "YES"
    return "NO"


print(main())
