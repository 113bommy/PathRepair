for _ in range(int(input())):
    n, k = map(int, input().split())
    if n%k == 0:
        print(n)
    else:
        res = (n//k) * k
        n = n%k
        res += min(n, k//2)
        print(res)