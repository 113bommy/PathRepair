n = int(input())
for _ in range(n):
    y, x = map(int, input().split())
    costs = list(map(int, input().split()))
    for i in range(36):
        costs[i % 6] = min(costs[i % 6], costs[(i+5) % 6] + costs[(i+1) % 6])
    ans = 0
    if x >= 0:
        if y >= 0:
            if x >= y:
                # 1
                ans = (x-y) * costs[0] + y * costs[1]
            else:
                # 2
                ans = x * costs[0] + (y-x) * costs[5]
        else:
            # 6
            ans = x * costs[1] - y * costs[2]
    else:
        if y >= 0:
            # 3
            ans = -x * costs[4] + y * costs[5]
        else:
            if x <= y:
                # 4
                ans = (y-x) * costs[4] - y * costs[3]
            else:
                # 5
                ans = (-x) * costs[3] + (x-y) * costs[2]
    print(ans)
