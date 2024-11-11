N = int(input())
r = [list(map(int, input().split())) for _ in range(N)]
a = []
for i in r:
    a.append((i[0]+i[1],i[0]-i[1]))
a.sort()
ans = 0
cur = a[0][1]
for i in a:
    if i[1] < cur:
        continue
    ans += 1
    cur = i[0]
print(ans)