n = int(input())
d = dict()
for i in range(n):
    a = [i for i in input().split()]
    if a[0] not in d.keys():
        d[a[0]] = set()
    for j in range(2, len(a)):
        d[a[0]].add(a[j])
print(len(d))

def check(a, b):
    if a not in b:
        return 0
    return (b.find(a) + len(a)) == len(b)

for nm, a in d.items():
    bad, a = set(), list(a)
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            if check(a[i], a[j]):
                bad.add(i)
            if check(a[j], a[i]):
                bad.add(j)
    print(nm, len(a) - len(bad), end=' ')
    for i in range(len(a)):
        if i not in bad:
            print(a[i], end=' ')
    print()
