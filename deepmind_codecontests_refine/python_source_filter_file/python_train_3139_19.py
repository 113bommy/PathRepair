import math

H, n = map(int, input().split())
a = list(map(int, input().split()))
pref = [0]
mini = 99999999999
for i in range(n):
    cur = pref[-1] + a[i]
    pref.append(cur)
    if -cur >= H:
        print(i + 1)
        exit()
if pref[-1] >= 0:
    print(-1)
    exit()

ans = 99999999999999
for i in range(n + 1):
    ans = min(ans, math.ceil((H + pref[i]) / -pref[-1]) * n + i)
print(ans)
