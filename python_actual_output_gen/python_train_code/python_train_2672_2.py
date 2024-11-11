while True:
    m = sum(map(int, input().split()))
    if not m:
        break
    n = int(input())
    fixed = [2] * m
    failures = []
    for _ in range(n):
        i, j, k, r = map(int, input().split())
        i, j, k = (x - 1 for x in (i, j, k))
        if r:
            fixed[i] = fixed[j] = fixed[k] = 1
        else:
            failures.append((i, j, k))

    for i, j, k in failures:
        fi, fj, fk = (fixed[x] for x in (i, j, k))
        if fi == 1:
            if fj == 1:
                fixed[k] = 0
            elif fk == 1:
                fixed[j] = 0
        elif fj == 1 and fk == 1:
            fi = 0

    print('\n'.join(str(x) for x in fixed))