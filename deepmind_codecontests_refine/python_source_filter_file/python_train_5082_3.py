h, w, n = map(int, input().split())
li = []
l = [w] * h
for _ in range(n):
    x, y = map(int, input().split())
    li.append((x - 1, y - 1))
li.sort()
cnt = 0
ans = w
for x, y in li:
    if x - cnt == y:
        cnt += 1
    elif x - cnt > y:
        ans = min(ans, x)
print(ans)

