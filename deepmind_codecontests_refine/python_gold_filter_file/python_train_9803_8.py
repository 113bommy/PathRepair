n = int(input())
mask = [0] * (n + 1)
cur = 1
for i in range(2, n + 1):
    if (mask[i] != 0): continue
    ind = 1
    while(i * ind <= n):
        if (mask[i * ind] != 0):
            ind += 1
            continue
        mask[i * ind] = cur
        ind += 1
    cur += 1
for i in range(2, n + 1):
    print(mask[i], end=' ')