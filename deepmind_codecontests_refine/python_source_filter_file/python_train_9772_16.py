dire = [0,0,0,0]
d = {c:i for i,c in numerate('WENS')}
for c in input():
	dire[d[c]] = 1
print('No' if (dire[0] ^ dire[1]) or (dire[2] ^ dire[3]) else 'Yes')