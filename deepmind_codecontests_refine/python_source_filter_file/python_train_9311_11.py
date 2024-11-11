n = int(input())
if n == 1:
    print(1)
else:
    a = [int(i) for i in input().split()]
    good = [[0 for j in range(2)] for i in range(n)]
    good[0][1] = 1
    for i in range(n):
        if a[i] > a[i - 1]:
            good[i][1] = good[i - 1][1] + 1
        else:
            good[i][1] = 1
    good[n - 1][0] = 1
    for i in range(n - 2, -1, -1):
        if a[i] < a[i + 1]:
            good[i][0] = good[i + 1][0] + 1
        else:
            good[i][0] = 1
    mx = max(good[1][0] + 1, good[n - 1][1] + 1)
    for i in range(1, n - 1):
        if a[i + 1] - a[i - 1] > 1:
            mx = max(mx, good[i - 1][1] + good[i + 1][0] + 1)
        mx = max(mx, good[i - 1][1] + 1, good[i + 1][0] + 1)
    print(mx)