def main():
    import sys
    from collections import defaultdict
    input = sys.stdin.readline

    N, x, d = map(int, input().split())

    if d == 0:
        if x:
            print(N+1)
        else:
            print(0)
        exit()

    if d < 0:
        x = x + d * (N-1)
        d *= -1
    dic = defaultdict(list)

    for i in range(N+1):
        mod = (x * i) % d
        st = (i * (i+1)) // 2
        ed = (i * (N + N-i+1)) // 2
        st = st * d + (x-d) * i
        ed = ed * d + (x-d) * i
        dic[mod].append((st, ed))
    ans = 0
    for mod in dic:
        L = dic[mod]
        L.sort(key=lambda t: t[0])
        ed_prev = L[0][0] - 1
        for st, ed in L:
            if st > ed_prev:
                ans += (ed - st) // d + 1
                ed_prev = ed
            elif ed > ed_prev:
                ans += (ed - ed_prev) // d
                ed_prev = ed
    print(ans)


if __name__ == '__main__':
    main()
