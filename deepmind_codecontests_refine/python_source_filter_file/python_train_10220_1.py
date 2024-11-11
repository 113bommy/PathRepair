for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    if n == 1:
        print(n + k)
        continue
    if a[n - 1] - a[0] <= 2*k:
        print(a[0] + k)
    else:
        print(-1)