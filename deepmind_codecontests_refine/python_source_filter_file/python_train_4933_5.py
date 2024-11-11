

ln0 = input()
ln1 = input()

n, s, t = map(int, ln0.split(' '))
P = list(map(lambda x: int(x) - 1, ln1.split(' ')))

if s == t:
    print(0)
    exit(0)

s -= 1
t -= 1
print(n, s, t, P)

static_ps = set()
p_map = {}
for i, p in enumerate(P):
    if p == i:
        static_ps.add(p)
    p_map[i] = p

if s in static_ps or t in static_ps:
    print(-1)
    exit(0)

processed = set()
groups = []

print(p_map)
curr_group = [next(iter(p_map.keys()))]

while p_map:
    k = curr_group[-1]
    if k in p_map:
        curr_group.append(p_map[k])
        del p_map[k]
    else:
        groups.append(curr_group)
        if p_map:
            curr_group = [next(iter(p_map.keys()))]

groups.append(curr_group)
print(groups)

for group in groups:
    group = group[1:]
    group_set = set(group)
    if s in group_set and t in group_set:
        si = group.index(s)
        ti = group.index(t)
        gn = len(group)
        res = (gn + ti - si) % gn
        print(res)
        exit(0)

print(-1)
exit(0)
