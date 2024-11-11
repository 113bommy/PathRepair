N = int(input())
pre = 0
ans = 0
for a in input().split():
    a = int(a)
    ans += max(a-pre, 0)
    pre = max(pre, a)
print(ans)