n = int(input())
a = list(map(int, input().split()))
ans = 1
m = 0
for i in range(n):
    if (a[i] - a[i - 1]) * m < 0:
        ans += 1
        m = 0
    elif a[i] - a[i - 1] != 0:
        m = a[i] - a[i - 1]
print(ans)