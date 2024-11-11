n = int(input())
a = list()
for i in range(n):
    a.append(list(map(int, input().split())))
a.append([1e9, 1e9])
ans = 1
i = 1
while i < n:
    if a[i][0] - a[i][1] > a[i - 1][0]:
        ans += 1
    elif a[i][0] + a[i][1] < a[i + 1][0]:
        ans += 1
        a[i][0] += a[i][1]
    i += 1
print(ans)
