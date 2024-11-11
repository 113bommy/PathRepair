def reminder(i: int):
    return i % 2


def calc(a: int, b: int):
    if a == b:
        return 0

    if a < b:
        if reminder(a) == 0 and reminder(b) == 0:
            return 2
        elif reminder(a) == 1 and reminder(b) == 1:
            return 2
        elif reminder(a) == 0 and reminder(b) == 1:
            return 1
        elif reminder(a) == 1 and reminder(b) == 0:
            return 1
    elif a > b:
        if reminder(a) == 0 and reminder(b) == 0:
            return 1
        elif reminder(a) == 1 and reminder(b) == 1:
            return 1
        elif reminder(a) == 0 and reminder(b) == 1:
            return 1
        elif reminder(a) == 1 and reminder(b) == 0:
            return 2


def main():
    for _ in range(int(input())):
        a, b = map(int, input().split())
        print(calc(a, b))


if __name__ == '__main__':
    main()
