def solve(l, r):
    if r - l > 1:
        mid = (l + r) // 2
        solve(l, mid)
        solve(mid + 1, r)
        for i in range(l, mid + 1):
            ans.append((i, mid + i))
    elif r - l == 1:
        ans.append((l, r))


n = int(input())
kiki = 1
while kiki * 2 <= n:
    kiki *= 2
ans = []
solve(1, kiki)
solve(n - kiki + 1, n)
print(len(ans))
for i in ans:
    print(*i)
