while True:
    n = int(input())
    if n == 0:
        break
    a = [int(input()) for _ in range(n)]
    minv = tmp = 0
    maxv = -50000
    for i in range(n):
        tmp += a[i]
        maxv = max(maxv, tmp - minv)
        minv = min(minv, tmp)
    print(maxv)