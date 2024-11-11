n, m = map(int, input().split())
ans = 0
for i in range(n):
    a = input().split()
    for s in range(0, m * 2, 2):
        if sum(map(int, a[s: s + 3])) > 0:
            ans += 1
print(ans)