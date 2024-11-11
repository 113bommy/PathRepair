t = int(input())
for p in range(t):
    n, m , k = [int(j) for j in input().split()]
    h = [int(j) for j in input().split()]
    f = 1
    if n == 1:
        print('Yes')
        continue
    for i in range(n - 1):
        if h[i] < h[i + 1]:
            if h[i + 1] - h[i] > k:
                m -= h[i + 1] - h[i] - k
            else:
                m += min(h[i], k - (h[i + 1] - h[i]))
        elif h[i] >= h[i + 1]:
            m += h[i] - h[i + 1] + min(k, h[i + 1])
        if m < 0:
            f = 0
            print('NO')
            break
    if f:
        print('YES')
