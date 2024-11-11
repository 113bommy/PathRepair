t = int(input())

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    x = 0
    xl = 0
    aa = sum(a)
    aal = len(a)
    ans = -10*9
    for i in a:
        h = a.pop()
        x += h
        aa -= h
        aal -= 1
        xl += 1
        if len(a) != 0:
            ans = max(ans, aa/aal + x/xl)
    print(ans)
