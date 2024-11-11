n, m = map(int, input().split())
if m == n:
    print(0)
elif m == n - 1:
    print(1)
else:
    print(min(n - m, m))