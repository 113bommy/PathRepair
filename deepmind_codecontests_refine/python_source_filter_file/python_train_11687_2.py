t = int(input())
for _ in range(t):
    n, k, l = [int(x) for x in input().strip().split()]
    d = [int(x) for x in input().strip().split()]
    left = -k
    f = 0
    for i in range(n):
        if d[i] > l:
            print('No')
            f = 1
            break
        d[i] = min(l - d[i], k)
        if d[i] <= k:
            left = -k
            continue
        if left >= d[i]:
            print('No')
            f = 1
            break
        left = max(-d[i], left + 1)
    if f == 0:
        print('Yes')