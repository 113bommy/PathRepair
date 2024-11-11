n, q = list(map(int, input().split()))
i = list(map(int, input().split()))
d = {1: i[:2]}
c = i.index(max(i))
for p in range(c + n - 1):
    if i[0] > i[1]:
        i.append(i[1])
        i.pop(1)
    elif i[0] < i[1]:
        i.append(i[0])
        i.pop(0)
    d[p + 2] = i[:2]
a = list(d)
for k in range(q):
    x = int(input())
    if x < (a[-1]):
        print(*d[x])
    else:
        print(*d[c + 1 + ((x - c - 1) % (n - 1))])
