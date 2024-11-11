for _ in range(int(input())):
    n,k = map(int,input().split())
    l = list(map(int,input().split()))
    f = 0
    for i in range(len(l)):
        x = l[i]
        if x > k//2:
            l[i] = 1
            continue

        if x < k//2:
            l[i] = 0
            continue

        l[i] = f
        f = f^1

    print(*l)