if __name__ == "__main__":
    n, k = map(int, input().split())
    width = 2 * k + 1
    rem = n % width
    print(n // width + bool(rem))
    shift = k if 0 < rem <= k else 0
    current = k + 1 - shift
    while current <= n:
        print(current, end=" ")
        current += width
    print()
