def main():
    s = input()
    lo, hi = 0, len(s)
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        cnt = dict.fromkeys("abcdefghijklmnopqrstuvwxyz", 0)
        for i in range(mid):
            cnt[s[i]] += 1
        v = {c for c, x in cnt.items() if not x}
        for i, c in zip(range(mid, len(s)), s):
            cnt[s[i]] += 1
            cnt[c] -= 1
            if not cnt[c]:
                v.add(c)
        if len(v) < 26:
            hi = mid
        else:
            lo = mid
    print(hi)


if __name__ == '__main__':
    main()
