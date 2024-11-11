def solve(n):
    s = list(map(int, input().split()))
    ind = [[] for _ in range(n+1)]
    for i in range(n):
        ind[s[i]].append(i)
    ans = [1000000]*(n+1)
    for i in range(1, n+1):
        k = 0
        length = len(ind[i])
        if length == 0:
            continue
        for j in range(length-1):
            k = max(ind[i][j+1]-ind[i][j], k)
        k = max(n-ind[i][-1], ind[i][0]+1, k)
        for j in range(k, n+1):
            if ans[j] > 300000:
                break
            ans[j] = i
    for i in range(1, n+1):
        if ans[i] > 300000:
            print(-1, end=' ')
        else:
            print(ans[i], end=' ')
    print()


for _ in range(int(input())):
    n = int(input())
    solve(n)
