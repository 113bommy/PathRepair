q = int(input())
for _ in range(q):
    n, m = [int(t) for t in input().split(' ')]
    a = [int(t) for t in input().split(' ')]
    b = [int(t) for t in input().split(' ')]

    level = 1
    plevel = {}

    for i, ai in enumerate(a):
        plevel[ai] = i

    summy = 0
    for step, bi in enumerate(b):
        if plevel[bi] > level:
            summy += (plevel[bi] - step) * 2 + 1
            level = plevel[bi]
        else:
            summy += 1

    print(summy)
