s = input()
n = len(s)
l = [[]for i in range(26)]

for i, c in enumerate(s * 2):
    l[ord(c) - ord('a')].append(i)


from bisect import *

shukai = 0
now = 0

t = input()
for c in t:
    x = ord(c) - ord('a')
    if len(l[x]) == 0:
        print(-1)
        exit()
    i = bisect(l[x], now)
    now = l[x][i] + 1
    if now >= n:
        now -= n
        shukai += 1


print(shukai * n + now)
