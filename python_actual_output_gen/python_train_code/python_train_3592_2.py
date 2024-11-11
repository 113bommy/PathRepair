inp = [int(x) for x in input().split(' ') if x]
d = {}
for x in inp:
    d[x] = d.get(x,0) + 1

vals = d.values()
if max(vals) < 3:
    print('Alien')
elif 1 in vals:
    print('Bear')
else:
    print('Elephant')
