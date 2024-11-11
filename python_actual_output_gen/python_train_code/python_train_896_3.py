def solve():
    #n = int(input())
    n, w = map(int, input().split())
    a = list(map(int, input().split()))
    #a = [list(map(int, input().split())) for _ in range(n)]
    mp = [[a[i], i] for i in range(n)]
    mp.sort()
    ans = [[mp[i][1], 0] for i in range(n)]
    mi = 0
    for i in range(n):
        t = max(mi, mp[0][0] // 2 + mp[0][0] % 2)
        ans[i][1] = t
        w -= t
        mi = t
    if w < 0:print(-1)
    else:
        for i in range(-1, -n - 1, -1):
            if w > mp[i][0] - ans[i][1]:
                w -= mp[i][0] - ans[i][1]
                ans[i][1] = mp[i][0]
            else:
                ans[i][1] += w
                break
        ans.sort()
        for i in range(n):
            print(ans[i][1], end=' ')

if __name__ == '__main__':
    solve()