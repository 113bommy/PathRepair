def main():
    n, k = map(int, input().split())
    res, cnt = 0, [0] * 10
    for a in map(int, input().split()):
        a, rest = divmod(a, 10)
        res += a
        cnt[rest] += 1
    for rest, x in enumerate(cnt[9::-1], 1):
        if k >= x * rest:
            k -= x * rest
            res += x
        else:
            print(res + k // rest)
            return
    print(min(res + k // 10, n * 10))


if __name__ == '__main__':
    main()
