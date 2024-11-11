for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    t = 0
    mm = max(a)
    for kk in range(11):
        if(2**kk > mm):
            break
    for k in range(1, 2**kk + 1):
        b = [None]*(n)
        for i in range(n):
            b[i] = a[i] ^ k
        if(a == sorted(b)):
            t = 1
            break
    if(t == 0):
        print("-1")
    else:
        print(k)