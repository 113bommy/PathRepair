d = {}
for i in range(int(input())):
    name, nick = map(str,input().split())
    if name in d.values():
        for k, v in d.items():
            if v == name:
                d[k] = nick
    else:
        d[name] = nick

print(d)
for i, j in d.items():
    print(i,j)
