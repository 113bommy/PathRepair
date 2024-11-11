n, m, k, x, y = map(int, input().split())
temp = k//m
if n == 1:
    ans1 = temp
    ans2 = temp
    if k%m > 0:
        ans1 += 1
    print(ans1, ans2, end = ' ')
    if y <= k%m:
        print(ans1)
    else:
        print(ans2)
else:
    div = temp//(n-1)
    a = []
    for i in range(0, n):
        a.append(0)
    div //= 2
    for i in range(0, n):
        a[i] += div*m
    for i in range(1, n-1):
        a[i] += div*m
    temp = k
    temp -= (div*2)*(n-1)*m
    while temp > 0:
        for i in range(0, n-1):
            a[i] += min(m, temp)
            temp -= min(m, temp)
            if temp == 0:
                break
        if temp == 0:
            break
        for i in range(n-1, 0, -1):
            a[i] += min(m, temp)
            temp -= min(m, temp)
            if temp == 0:
                break
        if temp == 0:
            break
    ans1 = max(a)//m
    ans2 = min(a)//m
    if max(a)%m > 0:
        ans1 += 1
    print(ans1, ans2, end = ' ')
    ans = a[x-1]//m
    if y <= a[x-1]%m:
        ans += 1
    print(ans)