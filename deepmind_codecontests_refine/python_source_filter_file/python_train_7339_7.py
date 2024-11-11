lines = [[] for i in range(8)]


for i in range(8):
    r = input()
    for c in range(8):
        lines[c].append(r[c])

min_bl = 10
min_wi = 10
for line in lines:
    if 'B' in line:
        rig_b = line[::-1].index('B')
        if 'W' in line:
            rig_w = line[::-1].index('W')
            if rig_b < rig_w:
                min_bl = min(min_bl, rig_b)
        else:
             min_bl = min(min_bl, rig_b)

    if 'W' in line:
        lef_w = line.index('W')
        if 'B' in line:
            lef_b = line.index('B')
            if lef_w < lef_b:
                min_wi = min(min_wi, lef_w)
        else:
             min_wi = min(min_wi, lef_w)

print('A' if (min_wi < min_bl) else 'B')