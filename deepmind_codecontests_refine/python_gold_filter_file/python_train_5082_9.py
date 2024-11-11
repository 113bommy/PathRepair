H, W, N = map(int, input().split())
xy = []
for i in range(N):
    x, y = map(int, input().split())
    xy.append((x, y))
xy.sort()

ans = H
d = 0
for x, y in xy:
    if x-d>y:
        ans = x-1
        break
    if x-d == y:
        d+=1
print(ans)




