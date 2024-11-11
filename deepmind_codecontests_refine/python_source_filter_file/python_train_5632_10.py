def main():
    n, m = map(int, input().split())
    if n > m:
        print(0)
        return
    cnt = {}
    for a in map(int, input().split()):
        cnt[a] = cnt.get(a, 0) + 1
    lo, hi = 1, 100
    for _ in range(8):
        mid, x = (lo + hi) // 2, n
        for c in cnt.values():
            x -= c // mid
        if x > 0:
            hi = mid
        else:
            lo = mid
    print(lo)


if __name__ == '__main__':
    main()
