x, y = list(map(int, input().split()))
a = [3] * y
ans = 0
while (1):
    if (a[0] == x and a[1] == x and a[2] == x):
        break
    a[0] = min(x, a[1] + a[2] - 1)
    a.sort()
    ans += 1
print(ans)