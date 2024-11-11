n = int(input())
data = [tuple(map(int, input().split())) for _ in range(n)]
ax, ay, ah = list(filter(lambda x:x[2], data))[0]

for cx in range(101):
    for cy in range(101):
        H = h + abs(ax-cx) + abs(ay-cy)
        if all(max(H-abs(d[0]-cx)-abs(d[1]-cy),0)==d[2]) for d in data):
            print(cx, cy, H)
            exit()