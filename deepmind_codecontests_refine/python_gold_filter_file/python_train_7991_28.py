n, k = map(int, input().split())
a = list(map(int, input().split()))

l, r = 1, 10 ** 9
while l < r:
    m = (l + r) // 2
    if sum(map(lambda v: (v - 1) // m, a)) > k:
        l = m + 1
    else:
        r = m
print(l)
