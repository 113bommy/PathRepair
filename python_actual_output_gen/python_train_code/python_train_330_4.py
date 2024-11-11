from sys import stdin
input = stdin.readline
n, m, d = map(int, input().split())
d -= 1
a = list(map(int, input().split()))
i = 1
ans = []
l = n - sum(a)
while l:
    t = [0] * min(l, d)
    l -= len(t)
    ans.extend(t)
    if a:
        ans.extend([i]*a.pop(0))
        i += 1
    else:
        if l > d:break
while a:
    ans.extend([i]*a.pop(0))
    i += 1
if len(ans) == n:
    print("YES")
    print(*ans)
else:print("NO")