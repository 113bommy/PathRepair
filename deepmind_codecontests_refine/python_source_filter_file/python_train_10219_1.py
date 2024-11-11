def valid(l, r, x, y):
    # if x <= 0 or y <= 0 or x >= len(l) or y >= len(r):
    #     return False
    # if l[x] <= r[y]:
    #     print(x, y, l[x], r[y])


    return l[x] > r[y]



if __name__ == '__main__':

    cin = lambda: [*map(int, input().split())]  #一行一行读

    n, k = cin()
    # print('n, k', n, k)
    x = cin()

    # print('x', x)

    l = [n + 1] * (n + 2)

    r = [-1] * (n + 2)

    vis = [0] * (n + 2)

    for i in range(k - 1, -1, -1):
        l[x[i]] = i

    for i in range(k):
        r[x[i]] = i

    for i in x:
        vis[i] = 1

    ans = n - sum(vis)
    ans = ans + sum(valid(l, r, x, x + 1) for x in range(1, n + 1))
    ans = ans + sum(valid(l, r, x, x - 1) for x in range(1, n + 1))

    print(ans - 2)