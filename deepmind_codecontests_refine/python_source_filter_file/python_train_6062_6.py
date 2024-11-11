for _ in range(int(input())):
    n,m = map(int, input().rstrip().split())
    a = list(map(int, input().rstrip().split()))
    if a[0] < m:
        t = m-a[0]
        if sum(a)-a[0] <= t:
            print((sum(a)))
        else:
            print(m)
    else:
        print("0")