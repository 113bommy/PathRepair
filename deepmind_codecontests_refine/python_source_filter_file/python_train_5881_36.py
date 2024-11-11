def main():
    _, start, end = [input() for _ in range(3)]
    ans = 0
    for s, e in zip(start, end):
        a, b = int(s), int(e)
        if b > a:
            a, b = b, a

        ans += min(a - b, 10 * b - a)

    print(ans)


if __name__ == "__main__":
    main()