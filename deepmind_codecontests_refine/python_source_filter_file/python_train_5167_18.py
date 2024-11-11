from collections import defaultdict

s = input()

symbols = defaultdict(list)
for i, c in enumerate(s):
	symbols[c].append(i)

dists = defaultdict(list)
for c, coords in symbols.items():
	deltas = []
	# deltas.append(coords[0])
	for x in range(1, len(coords)):
		deltas.append(coords[x] - coords[x - 1])
	deltas.append(len(s) - coords[-1])
	dists[c] = deltas

# print(dists)

ans = ((len(s) + 2) // 2)
for c in dists.keys():
	if len(dists[c]) > 0:
		ans = min(ans, max(dists[c]))

print(ans)