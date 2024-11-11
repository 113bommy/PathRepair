for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    k = 0
    l = 0
    r = 0
    for i in range(n):
        if a[i] == i + 1:
            k += 1
            if k == i + 1:
                l = k
            else:
                r += 1
        else:
            r = 0
    if k == n:
        ans = 0
    elif k == 0 or l + r == k:
        ans = 1
    else:
        ans = 2
    print(ans, l, r, k)
