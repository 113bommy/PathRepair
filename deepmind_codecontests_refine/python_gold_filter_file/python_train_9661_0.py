n = int(input())
a = list(map(int, input().split()))
a.sort()
q = 0
for ai in a:
    if ai < 0:
        q += 1
    else:
        break
if q == 0:
    q = 1
elif q == n:
    q = n - 1
ans = []
x = a[0]
for ai in a[q:-1]:
    ans.append([x, ai])
    x -= ai

ans.append([a[-1], x])
y = a[-1] - x

for ai in a[1:q]:
    ans.append([y, ai])
    y -= ai

print(y)
for i in ans:
    print(*i)
