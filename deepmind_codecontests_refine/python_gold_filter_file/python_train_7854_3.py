n = int(input())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))
a = sorted(a, key = lambda x: (x[0], x[1]))
cur = 0
ans = 1
for i in a:
    if cur <= i[1]:
        ans = max(ans, i[1])
        cur = i[1]
    else:
        ans = max(ans, i[0])
        cur = i[0]
print(ans)
