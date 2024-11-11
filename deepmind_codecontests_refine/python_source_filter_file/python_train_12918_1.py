n, m = map(int, input().split())
a = list(map(int, input().split()))
b = a[::]
a.sort()
tmp = a[-m]
cnt = 1
ans = tmp
for i in range(n-m + 1, len(a)):
    ans += a[i]
    if a[i] == a[i-1]:
        cnt += 1
c = []
count = 0
for i in range(len(b)):
    count += 1
    if b[i] > tmp:
        c.append(count)
        count = 0
    elif b[i] == tmp:
        if cnt > 0:
            c.append(count)
            count = 0
            cnt -= 1
c[-1] += count
print(ans)
for x in c:
    print(x, end=' ')
    