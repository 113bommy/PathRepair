def deep(ch, curn):
    s = 0
    for i in d[ch]:
        if i[0] in 'abcdef' and i[1] in 'abcdef':
            if curn and i[0] in d:
                s += deep(i[0], curn-1)
            elif i[0] in d:
                s += 1
    return s

n, m = map(int, input().split())
d = {}
for i in range(m):
    dec, en = input().split()
    if en in d:
        d[en].append(dec)
    else:
        d[en] = [dec]
if n == 1:
    print(1)
elif 'a' in d:
    print(deep('a', n-1))
else:
    print(0)
