n, m, p = map(int, input().split())
edge = []

for _ in range(m):
    a, b, c = map(int, input().split())
    edge.append([a-1, b-1, -c])

d = [float("inf") for _ in range(n)]
d[0] = 0

# check = [0 for _ in range(n)]

for i in range(n*2):
    for now, next, weight in edge:
        if d[next] > d[now] + weight + p:
            d[next] = d[now] + weight + p
            # n+1回目で更新された場合はループしているのでチェックを入れる
            if i > n-1:
                d[next] = -float("inf")
                # check[next] = 1
        if i == n-1:
            prev = d[-1]
            # if check[now]:
            #     check[next] = 1
        # print(d)

# print(check)
# if check[-1]:
if prev != d[-1]:
    print("-1")
else:
    print(max(-prev, 0))
    # print(prev)