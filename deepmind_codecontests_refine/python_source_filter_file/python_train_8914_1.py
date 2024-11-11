INF = int(1e9 + 7)

n = int(input())
a = list(map(int, input().split()))
suff = [INF] * (n + 1)
for i in range(n - 1, -1, -1):
    suff[i] = min(suff[i + 1], a[i])

ans = [0] * n
for i in range(n):
    L = i + 1 
    R = n
    if suff[i + 1] > a[i]:
        print(-1, end=' ')
        continue
    while R - L > 1:
        M = (R + L) // 2
        #print("{} {} {}".format(L, R, M))
        #print("{} {} {}".format(suff[L], suff[R], suff[M]))
        if suff[M] >= a[i]:
            R = M
        else:
            L = M
    print(R - i - 2, end=' ')
