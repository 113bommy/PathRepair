t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    maxi = 0
    maxj = 1
    used = [0] * n
    for i in range(1, k - 1):
        if a[i] > a[i - 1] and a[i + 1] < a[i]:
            used[i] = 1
            maxi += 1
    s = maxi
    # print(maxi)
    for i in range(k - 1, n - 1):
        if a[i] > a[i - 1] and a[i] > a[i + 1]:
            used[i] = 1
            s += 1
        if used[i - k + 2] == 1:
            s -= 1
        if s > maxi:
            maxi = s
            maxj = i - k + 3
        # print(i, s, maxi)
    print(maxi + 1, maxj)
