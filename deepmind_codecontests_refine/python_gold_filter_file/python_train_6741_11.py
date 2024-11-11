n, k, l = list(map(int, input().split()))
a = sorted(list(map(int, input().split())))
a = sorted(filter(lambda x: x - a[0] <= l, a))

# print(a)
if len(a) < n:
    print(0)
else:
    s = i = 0
    j = n
    m = len(a)
    while i < m - j:
        # print('--- ', i, m, j, m - j)
        s += a[i]
        # print(s, i, a[i])
        i += k
        j -= 1
    # print('---')
    for i in range(m - j, m):
        s += a[i]
        # print(s, i, a[i])
    print(s)