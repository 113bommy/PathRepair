n = int(input())
aa = list(map(int, input().split()))


def cal():
    ncol = [0] * (n + 1)
    ansmap = [0] * n
    ans = [0] * n
    colcnt = [0] * (n + 1)
    colmap = [0] * (n + 1)
    icol = 0
    for i, a in enumerate(aa):
        ncol[n - a] += 1
        ansmap[i] = n - a

    for i, col in enumerate(ncol[1:], 1):
        if col % i:
            return

    for i, col in enumerate(ansmap):
        if not colcnt[col] % col:
            icol += 1
        colmap[col] = icol
        ans[i] = colmap[col]
        colcnt[col] += 1

    return ans


ans = cal()
if ans:
    print('Possible')
    print(' '.join(map(str, ans)))
else:
    print('Impossible')
