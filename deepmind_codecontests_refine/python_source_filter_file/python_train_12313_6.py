def solve(a, x, y):
    if y % a == 0 or y <= 0:
        return -1

    row = y//a + 1

    if row == 1:
        return 1 if -a < x < a else -1

    if row % 2 == 0:
        return 2 + 3 * (row//2 - 1) if -a < x < a else -1
    else:
        d = (row - 3) // 2
        if 0 < x < a:
            return 4 + 3*d
        elif -a < x < 0:
            return 3 + 3*d
        else:
            return -1


def main():
    a, x, y = map(int, input().split())
    ans = solve(a, x, y)
    print(ans)


if __name__ == "__main__":
    main()
