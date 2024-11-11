import sys
from sys import stdin, stdout

try:
    n, k = map(int, stdin.readline().split())
    c_a = list(map(int, stdin.readline().split()))
    ceil = (n + k - 2) // (k - 1)

    co_a = [[] for _ in range(n)]
    for i in range(len(c_a)):
        co_a[c_a[i]-1].append(i)

    kc_a = [[] for _ in range(k)]
    for i in range(1, k):
        for j in range(n):
            # c, l, r
            kc_a[i].append([j, co_a[j][i-1], co_a[j][i]])

    res = {}
    for i in range(1, k):
        kc_a[i].sort(key=lambda x: x[2])

        cnt = 0
        for j in range(n):
            c, l, r = kc_a[i][j]
            if c in res:
                continue
            res[c] = [l + 1, r + 1]

            cnt += 1
            if cnt >= ceil:
                break

    for i in range(n):
        stdout.write(str(res[i][0]) + ' ' + str(res[i][1]) + '\n')

except:
    print(sys.exc_info()[0])
