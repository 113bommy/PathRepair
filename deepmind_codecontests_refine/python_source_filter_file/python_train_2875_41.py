n, k = map(int, input().split())
if (k == 0):
    print(0, 0)
else:
    mn = min(1, n - k)
    mx = min(k + 1, n - k)
    print(mn, mx)