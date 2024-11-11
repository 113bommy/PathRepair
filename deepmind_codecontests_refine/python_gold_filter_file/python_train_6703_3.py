def construct_path(dp, n):
    res = ''
    i = j = n-1
    while i > 0 or j > 0:
        if i > 0 and j > 0:
            if dp[i-1][j] < dp[i][j-1]:
                res += 'D'
                i -= 1
            else:
                res += 'R'
                j -= 1
        elif i > 0:
            res += 'D' * i
            break
        else:
            res += 'R' * j
            break
    return res[::-1]


n = int(input())

dp2 = [[0]*n for _ in range(n)]
dp5 = [[0]*n for _ in range(n)]
zi = zj = 0
has_zero = False
for i in range(n):
    t = list(map(int, input().split()))
    for j in range(n):
        if t[j] == 0:
            has_zero = True
            zi = i
            zj = j
        t2 = 0
        while t[j] > 0 and t[j] % 2 == 0:
            t[j] //= 2
            t2 += 1
        t5 = 0
        while t[j] > 0 and t[j] % 5 == 0:
            t[j] //= 5
            t5 += 1
        if i > 0 and j > 0:
            dp2[i][j] = min(dp2[i-1][j], dp2[i][j-1]) + t2
            dp5[i][j] = min(dp5[i-1][j], dp5[i][j-1]) + t5
        elif i > 0:
            dp2[i][j] = dp2[i-1][j] + t2
            dp5[i][j] = dp5[i-1][j] + t5
        elif j > 0:
            dp2[i][j] = dp2[i][j-1] + t2
            dp5[i][j] = dp5[i][j-1] + t5
        else:
            dp2[i][j] = t2
            dp5[i][j] = t5




res2 = dp2[n-1][n-1]
res5 = dp5[n-1][n-1]
res = ''
if has_zero and res2 > 0 and res5 > 0:
    res = 'D' * zi
    res += 'R' * zj
    res += 'D' * (n-zi-1)
    res += 'R' * (n-zj-1)
    print(1)
    print(res)
else:
    if res2 < res5:
        print(res2)
        print(construct_path(dp2, n))
    else:
        print(res5)
        print(construct_path(dp5, n))