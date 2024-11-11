t = int(input())


for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    mn = min(a)

    ans = 0
    i=0
    while ans < n//2:
        k = a[i]
        i+=1
        if k == mn:
            continue
        print(mn, k)
        ans+=1
