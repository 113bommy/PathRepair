n, l = map(int, input().split())
arr = [int(x) for x in input().split()]
arr.sort()
d = 0
for i in range(n - 1):
    d = max(d, arr[i + 1] - arr[i])
d = max(d, max(arr[0], l - arr[n - 1]))
r = d / 2
print(r)