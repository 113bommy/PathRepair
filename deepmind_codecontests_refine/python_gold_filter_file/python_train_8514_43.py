import bisect

s = input()
t = input()
if set(list(s + t)) != set(list(s)):
    print(-1)
    exit()
check = set(list(t))
dic = {}
for Str in check:
    dic[Str] = []
for i in range(len(s)):
    if s[i] in check:
        dic[s[i]] += [i]
times = 0
now = -1
for p in t:
    if now >= dic[p][-1]:
        now = dic[p][0]
        times += 1
    else:
        now = dic[p][bisect.bisect(dic[p], now)]
print(len(s) * times + now + 1)