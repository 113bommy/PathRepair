for _ in range(int(input())):
    n, k = map(int, input().split())
    if k <= n:
        print((n-k)%2)
    else:
        print(n-k)