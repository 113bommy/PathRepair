n = int(input())
a = [int(x) for x in input().split()]
a.sort()
l = 0
r = 0
res = 1
while True:
    while (r < n and a[r] - a[l] <= 5):
        r += 1
    res = max(res, r-l)
    if (r == n):
        break
    while (l < n and a[r] - a[l] > 5):
        l += 1
print(res)
    