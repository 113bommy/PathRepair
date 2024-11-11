n, m = map(int, input().split())
l = list(map(int, input().split()))
s = 0
for i in l: s += i
if n > s:
    print(-1)
    exit()
t = 1
ans = []
ind = -1
for i in range(m):
    if n  - (t + l[i] - 1) < 0:
        print(-1)
        exit() 
    if n - (t + l[i] - 1) <= s - l[i]:
        ans.append(t)
        t -= -1
        s -= l[i]
    else:
        t += ((n - (t + l[i] - 1)) - (s - l[i]))
        ans.append(t)
        ind = i + 1
        t += l[i]
        break
if ind != -1:
    for i in range(ind, m):
        ans.append(t)
        t += l[i]
print(*ans)