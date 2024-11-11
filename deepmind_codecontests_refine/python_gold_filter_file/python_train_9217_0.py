n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(len(a)):
    if a[i] == 0:
        ans += 1
    elif i != 0 and a[i] == a[i - 1] and a[i] != 3:
        ans += 1
        a[i] = 0
    elif a[i] == 3:
        a[i] -= a[i - 1]
print(ans)