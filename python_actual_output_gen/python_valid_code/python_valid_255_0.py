n = int(input())
t = [-(1 << 30)]
for i in range(n):
    t.append(int(input()))

dp = [0]
paid = 0
for i in range(1, n+1):
    cost = 20 + dp[-1]
    j = i - 1
    while j >= 0:
        if t[i] - t[j] > 90:
            cost = min(cost, 50 + dp[j])
            break
        j -= 1
    while j >= 0:
        if t[i] - t[j] > 1440:
            cost = min(cost, 120 + dp[j])
            break
        j -= 1

    dp.append(cost)
    print(cost - paid)
    paid = cost
