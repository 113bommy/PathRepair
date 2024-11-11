k, q = map(int, input().split())
d = [int(x) for x in input().split()]

for _ in range(q):
    n, x, m = map(int, input().split())
    z = 0
    last = x
    ans = 0

    for i in range(k):
        dnum = (n-1-i+(k-1))//k
        last += d[i]%m * dnum
        if d[i]%m == 0:
            z += dnum
        
    ans = (n-1) - (last//m - x//m) - z
    print(ans)
