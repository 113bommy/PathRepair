for hasju in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    for i in range(n * 2):
        if a[i] == 2:
            a[i] = -1
    ns = sum(a)
    ps1 = [0]
    for i in range(n - 1, -1, -1):
        ps1.append(ps1[-1] + a[i])
    ps2 = [0]
    for i in range(n, n * 2):
        ps2.append(ps2[-1] + a[i])
    ps1 = [[ps1[i], i] for i in range(len(ps1))]
    ps1.sort()
    ans = 5738927598279537293752398572398579
    for i in range(len(ps2)):
        rem = ns - ps2[i]
        l = -1
        r = len(ps1)
        while r - l != 1:
            s = (l + r) // 2
            if ps1[s][0] >= rem:
                r = s
            else:
                l = s
        if r == len(ps1) or ps1[r][0] != rem:
            continue
        else:
            ans = min(ans, i + ps1[r][1])
    if ans == 5738927598279537293752398572398579:
        print(n * 2)
    else:
        print(ans)
