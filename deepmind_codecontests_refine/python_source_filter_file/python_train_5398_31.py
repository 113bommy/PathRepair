N, K = map(int, input().split())
As = list(map(int, input().split()))

ans = 10**18
for i in range(1<<N):
    cnt = 0
    cost = 0
    mini = 0
    for j in range(N):
        J = As[j]
        if (i>>j)&1:
            cnt += 1
            if mini>J:
                cost += mini+1-J
                mini += 1
        mini = max(mini, J)
        if cnt>=K:
            ans = min(ans, cost)
print(ans)