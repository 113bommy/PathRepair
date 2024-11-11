n,m = map(int, input().split(' '))

a = set(input()[:m] for _ in range(n))

ps = []
mds = []



while len(a) > 0:
    i = a.pop()
    if i[::-1] in a:
        ps.append((i, i[::-1]))
        a.remove(i[::-1])
    else:
        if m & 1:
            if i[:m//2] == i[m//2+1:][::-1]:
                mds.append(i)
        elif i[:m//2] == i[m//2:][::-1]:
            mds.append(i)
fs = ""
ts = ""

for a,b in ps:
    fs += a
    ts = b + ts

if len(mds)>= 1:
    s = fs+mds[0]+ts
    print(len(s))
    print(s)
else:
    s = fs+ts
    print(len(s))
    print(s)