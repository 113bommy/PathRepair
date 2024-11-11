from itertools import combinations as cmb

s = input()

m = set()
for i in range(len(s)):
	m.update(set(cmb(s, i)))
p =set()
for i in m:
	if i == i[::-1]:
		p.add(i)
print(*max(p), sep='')