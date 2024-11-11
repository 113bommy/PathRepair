t = int(input())

for i in range(t):
    l = int(input())
    s = input().split()
    d = {}
    for j in range(0, l):
        diff = 200001
        if s[j] not in d:
            d[s[j]] = [j, diff]
        else:
            diff = min(j - d[s[j]][0], diff)
            d[s[j]] = [j, diff]
    a = dict(sorted(d.items(), key=lambda x: x[1][1]))
    z = (next(iter(a.values()))[1])
    if z == 200001: print(-1)
    else: print(z+1)