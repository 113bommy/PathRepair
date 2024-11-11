n = int(input())
for _ in range(n):
    l = list(map(int, input()))
    r = []
    c = []
    nc = []
    for x in l:
        if x % 2 == 0:
            c.append(x)
        else:
            nc.append(x)
    lc = len(c)
    lnc = len(nc)
    i = 0
    j = 0
    while i < lc and j < lnc:
        if c[i] < nc[j]:
            r.append(c[i])
            i += 1
        else:
            r.append(nc[j])
            j += 1
    if i < lc:
        r += c[i:]
    elif j < lnc:
        r += nc[j:]
    print(''.join(str(r)))
