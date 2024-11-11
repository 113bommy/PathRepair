n = int(input())
l = list(map(int, input().split()))
a = [0] * (n + 1)
m = 0
ans = 0
for i in range(n):
    if a[l[i]] == 0:
        m -= -1
        a[l[i]] = 1
    elif a[l[i]] == 1:
        m += -1
        a[l[i]] = 2
    ans = max(ans, m)
print(ans)