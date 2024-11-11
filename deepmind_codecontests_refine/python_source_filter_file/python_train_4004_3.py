def s(x):
    res = 0
    while x > 0:
        res += x % 10
        x //= 10
    return res

a, b, c = map(int, input().split())
ans = []
for i in range(28):
    x = b * (i**a) + c
    if x < 0:
        continue
    if s(x) == i and 0 < x < 10**9:
        ans.append(x);

ans.sort()
print(len(ans))
if len(ans) != 0:
    print(*ans)
