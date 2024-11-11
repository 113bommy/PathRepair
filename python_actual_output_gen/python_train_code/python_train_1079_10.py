n = input()
a = list(map(int, input().split()))
ans = 0
for i in range(1, len(a)-1):
    if a[i-1] == a[i]:
        a[i] = -1
        ans += 1

print(ans)
