n, k = [int(x) for x in input().split(' ')]
a = [int(x) for x in input().split(' ')]
b = [int(x) for x in input().split(' ')]

d = {}
for i in range(n):
    if a[i] in d.keys():
        d[a[i]].append(b[i])
    else:
        d[a[i]] = [b[i]]

lst = []
for (k, v) in d.items():
    v.remove(max(v))
    lst.extend(v)

lst.sort()
ans = sum(lst[:k - len(d)])
print(ans)
