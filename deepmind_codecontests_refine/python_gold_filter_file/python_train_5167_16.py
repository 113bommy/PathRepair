s = input()
a = set()
for char in s:
    a.add(char)
ans = list()
for i in a:
    n = list()
    n.append(-1)
    n.append(s.__len__())
    for j in range(0, s.__len__()):
        if i == s[j]:
            n.append(j)
    r = list()
    n = sorted(n)
    for j in range(1, n.__len__()):
        r.append(abs(n[j]-n[j-1]))
    ans.append((sorted(r)[-1]))
print(sorted(ans)[0])