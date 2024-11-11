n, c = map(int, input().split())
l = list(map(int, input().split()))
ans = 0
for i in range(1, n):
    if l[i] - l[i - 1] <= c:
        ans += 1
    else:
        ans = 1
print(ans)