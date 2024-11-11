def main():
    n = int(input())
    if n < 2:
        print(-1)
    else:
        print(*list(range(1, n + 1)))


main()
