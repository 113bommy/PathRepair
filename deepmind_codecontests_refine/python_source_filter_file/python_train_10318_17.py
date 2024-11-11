from collections import Counter

if __name__ == '__main__':
    n = int(input())
    sarr = list(map(int, input().split()))

    dct = Counter(sarr)

    if dct.most_common(1)[0][1] == 1:
        if n % 2:
            print('NO')
        else:
            print('YES')
            print(''.join(['A' if i % 2 else 'B' for i in range(n)]))
        exit(0)

    occ = list(filter(lambda o: o[1] == 1, dct.most_common()))

    if not occ:
        print('YES')
        print(''.join(['A' for i in range(n)]))
        exit(0)

    hn = None
    ndct = {}

    if len(occ) % 2:
        cmn = dct.most_common(1)[0]
        if cmn[1] < 3:
            print('NO')
            exit(0)
        hn = cmn[0]

    for i, o in enumerate(occ):
        if i % 2:
            ndct[o[0]] = 'B'

    rez = [None for _ in range(n)]

    for i, s in enumerate(sarr):
        if s in ndct:
            rez[i] = 'B'
        else:
            rez[i] = 'A'

    if hn:
        rez[sarr.index(hn)] = 'A'

    print('YES')
    print(''.join(rez))
