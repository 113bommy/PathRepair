n, k = map(int, input().split())
if k>=n:
    print(0, 0, n)
else:
    print((n//2)//(k+1), k*((n//2)//(k+1)), n - (n//2)//(k+1) - k*((n//2)//(k+1)))