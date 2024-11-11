from collections import Counter

n, k, m = map(int, input().split())
a = [(int(x) % m, int(x)) for x in input().split()]

d = dict()

for x, y in a:
    if (d.get(x, -1) != -1):
        d[x].append(y)
    else:
        d[x] = [y]

fl = False
for x in d:
    if len(d[x]) >= k:
        fl = True
        print("YES")
        print(*d[x][:k])
        break
if not fl:
    print("NO")