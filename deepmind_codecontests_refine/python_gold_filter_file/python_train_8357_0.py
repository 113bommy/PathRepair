max_N = 2001
inf = 1e10

T = int(input())
for t in range(T):
    n = int(input())
    a = [[]]
    for i in range(1, n + 1):
        s = input()
        a.append([0])
        for j in range(0, n):
            a[i].append(int(s[j]))

    min_row = [inf] * 10
    max_row = [0] * 10
    min_col = [inf] * 10
    max_col = [0] * 10

    ans = [0] * 10

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            x = a[i][j]
            min_row[x] = min(min_row[x], i)
            max_row[x] = max(max_row[x], i)
            min_col[x] = min(min_col[x], j)
            max_col[x] = max(max_col[x], j)

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            x = a[i][j]
            ans[x] = max(
                ans[x], max(max_row[x] - i, i - min_row[x]) * max(n - j, j - 1)
            )
            ans[x] = max(
                ans[x], max(max_col[x] - j, j - min_col[x]) * max(n - i, i - 1)
            )
    print(" ".join((map(str, ans))))
