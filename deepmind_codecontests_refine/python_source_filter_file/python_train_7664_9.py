n = int(input())
d = {}
for i in range(n):
    l = list(map(str, input().split()))
    if l[0] not in d:
        d[l[0]] = list(set(l[2:]))
    else:
        d[l[0]] = list(set(list(list(set(l[2:])) + d[l[0]])))
for i in d:
    a = d[i]
    ans = []
    m = len(a)
    for j in range(m):
        c = 1
        for z in range(m):
            if j != z and a[z].endswith(a[j]):
                c = 0
        if c:
            ans.append(a[j])
    d[i] = ans
print(len(d[i]))
for i in d:
    print(i, len(d[i]), *d[i])