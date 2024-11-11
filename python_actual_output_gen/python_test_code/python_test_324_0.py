n, m = map(int, input().split())
stack = [1]*n
p = [False]*n
p[0] = True

for i in range(m):
    x, y = map(int, input().split())
    stack[x-1] -= 1
    stack[y-1] += 1
    p[y-1] = p[x-1] or p[y-1]
    if stack[0] == 0:
        p[0] = False

ans = 0
for i in p:
    if i:
        ans += 1
print(ans)
