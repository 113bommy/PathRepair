n, l = map(int, input().split())
arr = sorted(list(map(int, input().split())))
mx = max(arr[0] * 2, l - arr[n-1] * 2)
for i in range(1, n):
    mx = max(mx, arr[i] - arr[i-1])
print("{0:0.10f}".format(mx / 2))