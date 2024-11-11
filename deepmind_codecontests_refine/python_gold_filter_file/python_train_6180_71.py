x = input().split()
d = {}
c = 0
for i in x:
    if i in d.keys():
        d[i] = d[i] + 1
    else:
        d[i] = 1
for j in d.values():
    if j > 1:
        c = c + j
    elif j == 1:
        c = c + 0
    else:
        pass
if c == 0:
    print(c)
elif c == 4:
    if len(d) == 1:
        print(c-1)
    else:
        print(c-2)
else:
    print(c-1)