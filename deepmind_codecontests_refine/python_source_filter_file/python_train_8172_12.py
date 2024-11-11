def foo(x):
    ans = 0
    for _ in range(1, x):
        ans += _
    return ans


pos = 2001 * [0]
neg = 1000 * [0]
for i in range(int(input())):
    x, y = map(int, input().split())
    pos[x + y] += 1
    neg[x - y] += 1
ans = 0
for j in range(len(neg)):
    ans += foo(neg[j])
for k in range(len(pos)):
    ans += foo(pos[k])
print(ans)
