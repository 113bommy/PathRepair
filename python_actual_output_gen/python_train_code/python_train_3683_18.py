n = int(input())
a = list(map(int, input().split()))
cnt = 1
b = []
for i in range(1, n):
    if a[i] == a[i - 1]:
        cnt += 1
    else:
        b.append(cnt)
        cnt = 1
b.append(cnt)
ans = 0
for i in range(1, n):
    ans = max(ans, min(a[i], a[i - 1]))
print(ans * 2)