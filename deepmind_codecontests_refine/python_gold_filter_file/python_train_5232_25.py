for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = sorted(range(n), key=lambda x: a[x])
    ans = 0
    c = 1
    for i in range(1, n):
        if b[i] > b[i - 1]:
            c += 1
        else:
            ans = max(ans, c)
            c = 1

    print(n - max(ans, c))