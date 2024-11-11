from collections import deque

n, b = [int(x) for x in input().split()]
d = deque()
ans = [0] * n
now = 0
j = 0
for i in range(n):
    t = [int(x) for x in input().split()]
    while len(d) != 0 and now <= t[0]:
        if d[0][0] > now:
            now = d[0][0] + d[0][1]
        else:
            now += d[0][1]
        d.pop()
        while ans[j] != 0:
            j += 1
        ans[j] = now
        j += 1
    if len(d) == b:
        ans[i] = -1
    else:
        d.append(t)
while len(d) != 0:
    if d[0][0] > now:
        now =  d[0][0] + d[0][1]
    else:
        now += d[0][1]
    d.pop()
    while ans[j] != 0:
        j += 1
    ans[j] = now
    j += 1
print(*ans)