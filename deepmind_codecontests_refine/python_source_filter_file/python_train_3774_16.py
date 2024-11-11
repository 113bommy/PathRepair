def check(a, b):
    cnt = 0
    for i in range(m):
        cnt += (a[i] != b[i])
    return cnt

for u in range(int(input())):
    n, m = map(int, input().split())
    matrix = [list(input()) for i in range(n)]
    cnt = []
    for i in range(m):
        cur = set()
        for j in range(n):
            cur.add(matrix[j][i])
        cnt += [list(cur)]
    s = ""
    ind = 0
    while ind < m:
        if len(cnt[0]) >= 2:
            break
        ind += 1
    if ind == m:
        s = matrix[0]
        print("".join(s))
        continue
    fl = 0
    for el in cnt[ind]:
        for i in range(n):
            if matrix[i][ind] != el:
                s = matrix[i].copy()
                s[ind] = el
                fl = 1
                for j in range(n):
                    if check(matrix[j], s) > 1:
                        fl = 0
                        break
            if fl:
                break
        if fl:
            break
    if fl:
        print("".join(s))
    else:
        print(-1)
