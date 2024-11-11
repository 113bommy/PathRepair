N = int(input())
A = [int(input()) for i in range(N)]


def ins_sort(a, n, g):
    count = 0
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j -= g
            count += 1
        a[j+g] = v
    return count


def shell_sort(a, n):
    cnt = 0
    *g, = []
    h = 0
    for i in range(0, n):
        h = h * 3 + 1
        if h >= n:
            break
        g.insert(0, h)

    m = len(g)
    for i in range(0, m):
        cnt += ins_sort(a, n, g[i])
    print(m)
    print(*g)
    print(cnt)
    for i in range(len(a)):
        print(a[i])


shell_sort(A, N)

