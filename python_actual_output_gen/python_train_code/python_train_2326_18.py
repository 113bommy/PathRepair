n, a = map(int, input().split())
c = list(map(int, input().split()))
ans = c[a - 1]
for i in range(1, min(a, abs(n - a) + 1)):
    ans += (c[a - 1 - i]&c[a - 1 + i]) * 2
if a == (n + 1) / 2:
    print(ans)
elif a < (n + 1) / 2:
    ans += sum(c[2 * a - 1:])
    print(ans)
else:
    ans += sum(c[:2 * a - n])
    print(ans)
