lens = int(input())
beut = [int(x) for x in input().split()]
dicts = {}
for i in range(lens):
    beut[i] -= i
    dicts[beut[i]] = dicts.get(beut[i], 0)
print(dicts)
for i in range(lens):
    dicts[beut[i]] += beut[i] + i


print(max(dicts.values()))
