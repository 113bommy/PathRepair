n, m, k, x, y = map(int, input().split())
if k < n * m:
    print('1 0', end=' ')
    if (x - 1) * m + y - 1 >= k:
        print(0)
    else:
        print(1)
else:
    a = 1
    if n != 1:
        k -= n * m
        a += k // (2 * (n - 1) * m) * 2
        k = k % (2 * (n - 1) * m)
        our = [[0] * m for i in range(n)]
        for i in range(m):
            our[0][i] = a // 2 + 1
            our[-1][i] = a // 2 + 1
        for i in range(1, n - 1):
            for j in range(m):
                our[i][j] = a
        curr_i = n - 2
        curr_j = 0
        diff = -1
        while k > 0:
            k -= 1
            curr_j += 1
            if curr_j == m:
                curr_j = 0
                curr_i += diff
                if curr_i == -1:
                    curr_i += 2
                    diff = 1
                elif curr_i == n:
                    curr_i -= 2
                    diff = -1
            our[curr_i][curr_j] += 1
        ma = 0
        mi = 10 ** 300
        for elem in our:
            ma = max(ma, max(elem))
            mi = min(mi, min(elem))
        print(ma, mi, our[x - 1][y - 1])
    else:
        a = k // m
        k %= m
        if k == 0:
            print(a, a, a)
        else:
            print(a + 1, a, a + (1 if y <= k else 0))
    