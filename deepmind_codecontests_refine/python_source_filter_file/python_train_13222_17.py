def insertionsort(a, n, g):
    cnt = 0
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j + g] = a[j]
            j = j - g
            cnt += 1
        a[j + g] = v
    return cnt


def shellsort(a, n):
    g = []
    gap = 1
    while gap <= n / 9:
        g.append(gap)
        gap = 3 * gap + 1
    g = g[::-1]
    m = len(g)
    print(m)
    print(*g)
    cnt = 0
    for i in range(m):
        cnt += insertionsort(a, n, g[i])
    print(cnt)

n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
shellsort(a, n)
print("\n".join(map(str, a)))