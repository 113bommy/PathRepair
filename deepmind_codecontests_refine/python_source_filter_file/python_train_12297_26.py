def main():
    n = int(input())
    for i in range(n):
        s, p = [int(v) for v in input().split()]
        if s % 2 == 0 and p % 2 != 0:
            print(-1 * (p - s + 1) // 2)
        elif s % 2 == 0 and p % 2 == 0:
            print(-1 * (p - s) // 2 + p)
        elif s % 2 != 0 and p % 2 == 0:
            print(1 * (p - s) // 2)
        elif s % 2 != 0 and p % 2 != 0:
            print(1 * (p - s) // 2 - p)


if __name__ == "__main__":
    main()
