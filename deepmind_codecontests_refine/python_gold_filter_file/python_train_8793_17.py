def Calculate(n,m):
    if n == m:
        return 0
    elif n > m:
        return n-m
    elif m%2 == 0:
        return Calculate(n, m/2) + 1
    else:
        return Calculate(n, m+1) + 1

n, m = map(int, input().split())
print(int(Calculate(n,m)))
