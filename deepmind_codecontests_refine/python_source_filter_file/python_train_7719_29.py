def f(n, m):
    if m == 0:
        return 1
    if m < n//2:
        return m
    else:
        return n-m

n, m = map(int, input().split())
print(f(n, m))