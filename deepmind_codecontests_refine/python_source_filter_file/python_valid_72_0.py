for _ in range(int(input())):
    n, k = map(int, input().split())
    d = [int(x) for x in str(n)]
    l = len(d)

    if n == 1000000000:
        print(111111111 if k == 1 else 1000000000)
        continue
    if k >= len(set(d)):
        print(n)
        continue

    mn = 10 ** 15
    for i in range(l):
        for v in range(d[i]+1, 10):
            uniq = set(d[:i]) | {v}
            if len(uniq) > k:
                continue
            elif len(uniq) < k:
                uniq |= {0}
            nd = d[:i] + [v] + [min(uniq)] * (l - i - 1)
            nn = int(''.join(map(str, nd)))
            if nn < mn:
                mn = nn
    print(mn)
