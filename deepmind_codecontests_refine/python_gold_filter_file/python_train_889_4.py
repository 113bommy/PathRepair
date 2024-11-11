n, m = map(int, input().split())
a = list(map(int, input().split()))

ans = 0
for i in range(m):
    li, ri = map(int, input().split())
    tmp = sum(a[li - 1: ri])
    if tmp > 0:
        ans += tmp

# ans = max(ans, sum(a)) # 全部選択したときの考慮

print(ans)