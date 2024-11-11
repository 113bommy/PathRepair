def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    arr1 = []
    arr2 = []
    for i in range(n):
        arr1.append([a[i], i])
        arr2.append([b[i], i])
    arr1.sort()
    arr2.sort()
    d = {}
    ind = -1
    for i in range(n - 1, -1, -1):
        d[arr1[i][1]] = 1
        d[arr2[i][1]] = 1
        if len(d) == n - i:
            ind = i
            break
    ans = [0 for i in range(n)]
    for i in range(ind, n):
        ans[i] = 1
    print(*ans, sep = '')
t = int(input())
for tc in range(t):
    solve()