from collections import Counter


def main():
    input()
    cnt = Counter(map(int, input().split()))
    a, *rest = sorted(cnt.keys())
    pool, res = cnt[a], 0
    for a in rest:
        c = cnt[a]
        if pool < c:
            res += pool
            pool = c - pool
        else:
            res += c
    print(res)


if __name__ == '__main__':
    main()
