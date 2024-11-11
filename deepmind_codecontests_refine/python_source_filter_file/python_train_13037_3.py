for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    d = {}
    for i in a:
        d[i] = d.get(i, 0) + 1
    ans = 0
    d1 = {}
    for i in range(n):
        if d1.get(a[i], 0) + 1 <= d[a[i]] // 2:
            maxx = 0
            d2 = {}
            d1[a[i]] = d1.get(a[i], 0) + 1
            x = d1[a[i]]
            j = i + 1
            while d[a[i]] - d2.get(a[i], 0) - d1[a[i]] > 0:
                if a[i] == a[j]:
                    d2[a[i]] = d2.get(a[i], 0) + 1
                else:
                    d2[a[j]] = d2.get(a[j], 0) + 1
                    maxx = max(maxx, d2[a[j]])
                j += 1
            ans = max(ans, maxx + 2 * x)
        else:
            ans = max(ans, d[a[i]])
    print(ans)
