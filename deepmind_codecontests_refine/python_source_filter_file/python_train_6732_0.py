def main():
    n, k, l = map(int, input().split())
    a = sorted(map(int, input().split()))

    bound = 1
    while bound < len(a) and a[bound] - a[0] <= l:
        bound += 1

    if bound < n:
        print(0)
        return

    res = 0

    i = 0
    while n > 0:
        res += a[i]
        i = min(i + k, bound - n)
        n -= 1

    print(res)


main()
