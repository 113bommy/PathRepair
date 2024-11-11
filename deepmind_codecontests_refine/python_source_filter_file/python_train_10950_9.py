n, k = map(int, input().split())
d = {}
ls = []
for x in list(map(int, input().split())):
    if d.get(x) == None:
        d[x] = 0
        ls.append(x)
        if len(ls) > k:
            d[ls[0]] = None
            del ls[1:]
print(len(ls))
ls.reverse()
print(' '.join(map(str, ls)))