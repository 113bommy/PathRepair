t = int(input())
for z in range(t):
    n, p = [int(x) for x in input().split()]
    cur = 0
    for i in range(1, n):
        j = i + 1
        while (j <= n) and (cur < n*2 + p):
            print(i, j)
            j += 1
            cur += 1