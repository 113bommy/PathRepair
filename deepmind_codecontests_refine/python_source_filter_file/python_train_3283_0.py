lines = []

from collections import defaultdict

d = {}

while True:
    try:
        x = input();
        if len(x) == 0:
            break
        x = x.split("\\")
        lines.append(x[1:])
        curr_d = d

        for i in range(0, len(x) - 1):
            curr = x[i]

            if curr in curr_d:
                pass
            else:
                curr_d[curr] = {}

            curr_d = curr_d[curr]

        curr_d[x[-1]] = 1
    except Exception as e:
        break

def dfs2(dic):
    fil = 0

    for key in dic.keys():
        val = dic[key]
        if type(val) == int:
            fil += 1
        else:
            fil += dfs2(val)

    return fil

def dfs1(dic):
    fil = 0

    for key in dic.keys():
        val = dic[key]

        if type(val) == int:
            pass
        else:
            fil += 1
            fil += dfs1(val)

    return fil

a1, a2 = 0, 0
for drive in d.keys():
    for folder in d[drive].keys():
        a2 = max(a2, dfs2(d[drive][folder]))
        a1 = max(a1, dfs1(d[drive][folder]))

print(d)
print(a1, a2)
