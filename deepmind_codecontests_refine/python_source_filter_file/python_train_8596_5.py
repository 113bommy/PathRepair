n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
ans = 0
cnt = 0
bought = set()
for i in range(n):
    if a[i] <= b[i]:
        ans += a[i]
        cnt += 1
        bought.add(i)
c = {i: b[i] - a[i] for i in range(n) if i not in bought}
c = sorted(((i, diff) for i, diff in c.items()), key=lambda x: x[1])
for i, diff in c:
    if cnt < k:
        cnt += 1
        ans += a[i]
    else:
        ans += b[i]
print(ans)