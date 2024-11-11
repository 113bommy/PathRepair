def main():
    n = int(input())
    if n < 2:
        print(-1)
    else:
        print(*list(range(n)))


main()
