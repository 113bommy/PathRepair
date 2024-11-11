n = int(input())
ans = 0
t = 10000000000000
for i in range(n):
    a, b = map(int, input().split())
    ans += a
    if a > b:
        t = min(t, b)
print(max(0, ans - t))
