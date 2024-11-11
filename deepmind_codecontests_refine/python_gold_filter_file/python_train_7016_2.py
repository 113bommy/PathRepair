
x = []
y = []
for i in range(8):
    xi, yi = map(int, input().split())
    x.append(xi)
    y.append(yi)

xtmp = sorted(x)
ytmp = sorted(y)

xdist_list = [xtmp[0]]
ydist_list = [ytmp[0]]
for i in range(1, 8):
    if xtmp[i] != xtmp[i-1]:
        xdist_list.append(xtmp[i])
    if ytmp[i] != ytmp[i-1]:
        ydist_list.append(ytmp[i])

if len(xdist_list) != 3 or len(ydist_list) != 3:
    print('ugly')
    exit()

full_eight_points_set = []
for i in range(3):
    for j in range(3):
        if i != 1 or j != 1:
            found = False
            for k in range(8):
                if x[k] == xdist_list[i] and y[k] == ydist_list[j]:
                    found = True
                    break
            if not found:
                print('ugly')
                exit()
print('respectable')


