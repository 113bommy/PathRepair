n, x, m = map(int, input().split())

a = x
li = [a]
exists = dict()
for i in range(2, n + 1):
    a = a * a % m
    if a in exists:
        break
    li.append(a)
    exists[a] = i

ans = sum(li)
if i != n:
    loop, left = divmod(n - i + 1, i - exists[a])
    ans += loop * sum(li[exists[a]-1:]) + sum(li[exists[a]-1:exists[a]-1+left])
print(ans)
