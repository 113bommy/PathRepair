n, k = map(int, input().split())
arr = list(map(int, input().split()))

l = 1
r = max(arr)

while l + 1 < r:
    m = (l + r) // 2

    cut = 0
    for x in arr:
        cut += (x - 1) // m

    if cut > k:
        l = m
    else:
        r = m

print(r)