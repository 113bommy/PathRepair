t = int(input())
for i in range(t):
    n = int(input())
    maxl = -1
    minr = int(1e9)
    for j in range(n):
        l, r = map(int, input().split())
        maxl = max(maxl, l);
        minr = min(minr, r)
    if (minr > maxl):
        mainr, maxl = maxl, minr
    print(minr, maxl)