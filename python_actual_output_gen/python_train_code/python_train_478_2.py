n = int(input())
a = list(map(int, input().split()))
ma = a[0]
ans = 1
for i in range(1, len(a)):
    ma = max(ma, a[i])
    if i + 1 == ma:
        ans += 1
print(ans)
