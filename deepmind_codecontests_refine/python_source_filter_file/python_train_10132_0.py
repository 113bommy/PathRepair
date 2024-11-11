t = int(input())

for _ in range(t):
    n, l, r, s = list(map(int, input().split()))

    els = []
    sels = 0
    nb = r - l + 1

    els = [i+1 for i in range(nb)]
    sels = (nb+1)*nb//2

    if sels >= s:
        print(-1)
        continue

    i = len(els)-1
    while sels < s and i >= 0:
        if sels + (n - nb) < s:
            els[i] += n - nb
            sels += n - nb
        else:
            delta = s - sels
            els[i] += delta
            sels = s
        i -= 1

    if sels < s:
        print(-1)
        continue

    j = 1
    k = 0
    for i in range(1, n+1):
        if i < l or i > r:
            while j in els:
                j += 1
            print(j, end=' ')
            j += 1
        else:
            print(els[k], end=' ')
            k += 1

    print()